//
//  main.cpp
//  helloworld
//
//  Created by APPLE on 10/1/23.
//

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cctype>
#include <sstream>
#include <fstream>
#include <vector>

using namespace std;

class lexical_analyzer{
    string code;
public:
    lexical_analyzer(string input_code){
        this->code=input_code;
    };
    
    // defining function to catch special characters
    vector<char> detect_special_characters( string input){
        
        //creating an array of special characters
        string special= "[]{})(@<>;/";
        
        //defing a vector to return
        vector<char> detect_numbers;
        //looping over the string
        for(int i=0;i<input.length();i++){
            
            for(int j=0;j<size(special);j++){
                
                if( input[i]==special[j]){
                    detect_numbers.push_back(input[i]);
                    
                };
                
                
            };
           
        };
        return detect_numbers;
    };
    
    vector<string> detect_numbers(string numbers) {
        vector<string> detect;
        string num;
        for (int i = 0; i < numbers.length(); i++) {
            char target = numbers[i];
            if (target == ' ' || target == '=') {
                int j = i + 1;
                while (j < numbers.length() && isdigit(numbers[j])) {
                    num += numbers[j];
                    j++;
                }
                if (!num.empty()) {
                    detect.push_back(num);
                    num = "";
                }
                i = j;
            }
        }
        return detect;
    }
    
    //defing function to detect keywords
    vector<string> detect_keywords(string input){
        vector<string> keywords = {
             "if", "else", "for", "while", "int", "float", "double", "return","#include","int","float","#include",
             // Add more keywords as needed
         };

         vector<string> detectedKeywords;
         
         // Create a stringstream to tokenize the input string
         stringstream ss(input);
         string word;

         // Tokenize the input string by spaces
         while (ss >> word) {
             // Check if the word is a keyword
             for (const string& keyword : keywords) {
                 if (word == keyword) {
                     detectedKeywords.push_back(word);
                     break;
                 }
             }
         }

         return detectedKeywords;
    };
    
    // defing function to detect identifiers
    
    vector<string> detect_indentifiers( string input){
        // Define a list of keywords you want to exclude
           vector<string> keywords = {
               "if", "else", "for", "while", "int", "float", "double", "return","#include","if else",")","(","]",
               // Add more keywords as needed
           };

           vector<string> detectedIdentifiers;
           
           // Create a stringstream to tokenize the input string
           stringstream ss(input);
           string word;

           // Tokenize the input string by spaces
           while (ss >> word) {
               // Check if the word is not a keyword (i.e., an identifier)
               bool isIdentifier = true;
               for (const string& keyword : keywords) {
                   if (word == keyword) {
                       isIdentifier = false;
                       break;
                   }
               }

               // If it's an identifier, add it to the detectedIdentifiers vector
               if (isIdentifier) {
                   detectedIdentifiers.push_back(word);
               }
           }

           return detectedIdentifiers;
    };
    
    bool check_function_declaration(string input ){
        string word;
        bool present=false;
        vector<string> all;
        string keywords[4]
              = { "int", "float", "void", "double" };
        int count=0;
        stringstream ss(input);
        while (ss >> word) {
            // Check if the word is a keyword
            all.push_back(word);
            
            
        }
        for(string e:all){
            cout<<endl<<e<<endl;
        }
        for(string e : keywords){
            if(all[0]==e and count==0){
                present=true;
                count++;
                
            }
            }
        if(present==false){
            return false;
        }
        
        cout<<endl<<present<<endl;
            
        
        present=false;
        for (string e:all){
            
            if(e=="("){
                for(string e:all){
                    if(e==")"){
                        present=true;
                    }
                }
                if(present==false){
                    return false;
                }
                
                
            }}
                cout<<endl<<present<<endl;
                
                present=false;
        for(string e:all){
            
                if(e=="{"){
                    for(string e:all){
                        if(e=="}"){
                            present=true;
                        }
                    }
                    if(present==false){
                        return false;
                    }
                    
                    
                }
            
            
            
            
        }
        
        
        
        
        
        
        return present;
    }
    
    void remove_useless_code(string code){
        string word;
        vector<string> alpha;
        
        stringstream ss(code);
        while (ss >> word) {
            // Check if the word is a keyword
            alpha.push_back(word);
            
            
        }
        
        for(string e:alpha){
            if(e=="for"){
                for(string e:alpha){
                    if(e=="{"){
                        
                        
                    }
                }
            }
            
        }
        
        
        
        
        
    }
    
};

string readCodeFromFile(string& filename) {
    ifstream file(filename); // Open the file
    string code; // String to store the code

    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            code += " "+line ;
        }
        file.close(); // Close the file
    } else {
        cerr << "Failed to open the file." << std::endl;
    }

    return code;
}


int main(int argc, const char * argv[]) {
    
    int shaheen;
    bool tr;
    string filename="/Users/apple/Desktop/read";
    string code=readCodeFromFile(filename);
    lexical_analyzer obj(code);
    vector<string> identifiers;
    string fun=" float num ( string input ) { }";
    identifiers=obj.detect_keywords(code);
    for(string e:identifiers){
        cout<<endl<<e<<endl;
    }
    
   
    
    
    
    
    return 0;
}
