/* 
 * File:   Communication.h
 * Author: Nathan Hansen
 *
 * Created on April 13, 2012, 8:18 PM
 */

#ifndef COMMUNICATION_H
#define	COMMUNICATION_H
#include <string>
#include <vector>
namespace Model {

    class Communication {
    public:
        Communication() {
            command = "";
            arguments.clear();
        }
        Communication(const Communication& orig) {
            this->command = orig.command;
            this->arguments = orig.arguments;
        }
        std::string command;
        std::vector<std::string> arguments;
    private:

    };
}
#endif	/* COMMUNICATION_H */

