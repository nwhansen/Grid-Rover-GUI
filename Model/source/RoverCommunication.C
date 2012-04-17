/* 
 * File:   RoverCommunication.C
 * Author: Nathan Hansen
 * 
 * Created on April 14, 2012, 10:23 AM
 */

#include "RoverCommunication.h"
#include <string>
#include <sstream>
#include <vector>

std::vector<std::string> split(const std::string &s, char delim);

bool RoverCommunication::SendFormattedMessage(AbstractModelNameSpace::Communication& toSend){
    std::stringstream toWrite(toSend.command);
    toWrite << " ";
    for(unsigned int i = 0; i < toSend.arguments.size(); i++) {
        if(i == (toSend.arguments.size()-1)) {
            toWrite << toSend.arguments[i] << std::endl;
        } else toWrite << toSend.arguments[i] << " ";
    }
   return this->SendRoverCommand(toWrite.str());
}

AbstractModelNameSpace::Communication RoverCommunication::RecieveFormattedMessage(){
    //This is going to suck...
    //We need to read from the buffer and only send back one formated command. if we get more we will need to cache the info.
    remaining << this->getRoverCommand();
    //Utilizing get line 
    std::string roverMessage;
    std::getline(remaining, roverMessage);
    //Ok lets try this.
    //Lets assume only valid communication.
    if(roverMessage.length() == 0)
        return AbstractModelNameSpace::Communication();
    //Lets splot this shit!
    std::vector<std::string> brokenMessage = split(roverMessage, ' ');
    if(brokenMessage.size() == 0)
        return AbstractModelNameSpace::Communication();
    AbstractModelNameSpace::Communication message;
    message.command = brokenMessage[0];
    //Start at one to skip the first element. There is most likely an easier way to do this but it works for now.
    for(unsigned int i =1; i < brokenMessage.size(); i++){
        message.arguments.push_back(brokenMessage[i]);
    }
    return message;
}

std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
    std::stringstream ss(s);
    std::string item;
    while(std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}


std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    return split(s, delim, elems);
}
