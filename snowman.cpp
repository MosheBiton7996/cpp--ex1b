#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
#include "snowman.hpp"

using namespace std;
enum  bodyParts{head, nose, leftEye, rightEye, leftArm, rightArm, torso, base};
const int minval = 11111111, maxval = 44444444;

const vector<string> Head = {"       \n _===_ ", "  ___  \n ..... ", "   _   \n  /_\\  ", "  ___  \n (_*_) "};
const vector<string> X1 = {" ", "\\", " ", " "};
const vector<string> Eye = {".", "o", "O", "-"};
const vector<string> Nose = {",", ".", "_", " "};
const vector<string> Y1 = {" ", "/", " ", " "};
const vector<string> X2 = {"<", " ", "/", " "};
const vector<string> Torso = {" : ", "] [", "> <", "   "};
const vector<string> Y2 = {">", " ", "\\", " "};
const vector<string> Base = {" : ", "\" \"", "___", "   "};

int charToInt(char part){ return ((part - '0') - 1);}

namespace ariel{
    string snowman(int num){
        if (num < minval || num > maxval){
            throw invalid_argument{"Unvalid number format. Requires 8 digits, digits between 1-4.\n"};
        }
        
        string snowy = to_string(num);
        try{
            return Head.at(charToInt(snowy[head])) 
            + "\n" + X1.at(charToInt(snowy[leftArm])) + "(" + Eye.at(charToInt(snowy[leftEye])) + Nose.at(charToInt(snowy[nose]))
                    + Eye.at(charToInt(snowy[rightEye])) + ")" + Y1.at(charToInt(snowy[rightArm])) 
                    + "\n" + X2.at(charToInt(snowy[leftArm])) 
                    + "(" + Torso.at(charToInt(snowy[torso])) + ")" + Y2.at(charToInt(snowy[rightArm])) 
                    + "\n" + " (" + Base.at(charToInt(snowy[base])) + ") ";
        }
        catch (exception& ){
            throw out_of_range{"Unvalid number format. Requires digits between 1-4.\n"};
        }
    }
};