#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

class Tag {
    public:
    string name;
    map<string, string> attrs;
    map<string, Tag *> childTags;
    
    Tag() {} 
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int num_lines, num_queries;
    
    cin >> num_lines;
    cin >> num_queries;
    
    //get the newline char that's left
    string line;
    getline(cin,line);
    
    vector<Tag *> tagStack;
    Tag masterTag;
    masterTag.name = "masterTag";
    Tag *currentTag = &masterTag;
    tagStack.push_back(&masterTag);    

    for (int i = 0; i < num_lines; i++) {
        getline(cin,  line);
        //search for the start of a tag
        if (line.substr(0,2) == "</") {    //end tag
            //pop a tag pointer off the stack (we're not deleting the Tag tho!)
            tagStack.pop_back();
            currentTag = tagStack.back();
        } else if (line[0] == '<') {
            //create a new tag
            Tag *thisTag = new Tag();
            
            //parse the tag Name
            string name;
            int pos;
            if ((pos = line.find(' ')) == string::npos) {
                name = line.substr(1, line.length()-2);
            } else {
                name = line.substr(1,pos - 1);
                line.erase(0, pos + 1);
            }
            thisTag->name = name; //actually I don't strictly think this is necessary
            
            //parse the attributes
            vector<string> attrs;
            string token;
            while ((pos = line.find(' ')) != string::npos) {
                token = line.substr(0, pos);
                //check if it's an "="
                if (token != "=") {
                    //check if we need to remove quotes
                    if (token[0] == '"') {
                        token = token.substr(1,pos-2); //1 because w're starting at 1, 1 because we need to remove the quotes
                    }
                    attrs.push_back(token);                    
                }
                line.erase(0, pos + 1);
            }
            //last token...
            token = line;
            //check if we need to remove quotes
            if (token[0] == '"') {
                token = token.substr(1,token.length()-3);
            }
            attrs.push_back(token);  
            
            //populate the attributes
            for(int j = 0; j < attrs.size()/2; j++) {
                thisTag->attrs[attrs[2*j]] = attrs[2*j+1];
                //cout << thisTag->name << "[" << attrs[2*j] << "]" << " = " << attrs[2*j+1] << endl;
            }
            
            //add this tag to the stack
            tagStack.push_back(thisTag); 
            //add the newly created tag as a child tag
            //cout << name << " has been added to " << currentTag->name << endl;
            currentTag->childTags[name] = thisTag;
            //set a new active tag
            currentTag = thisTag;   
        } else {
            cout << "Something's wrong, line = (" << line << ")" << endl;
        }
    }
    for (int i = 0; i < num_queries; i++) {
        //parse the query
        getline(cin,  line);
        
        //parse the attribute
        int pos;
        string attr;
        if ((pos = line.find('~')) == string::npos) {
            cout << "Not Found!" << endl;
            continue;
        } else {
            attr = line.substr(pos+1, line.length());
            line.erase(pos, line.length());
        }
        
        //parse the stack of tag names
        vector<string> tagNames;
        string token;
        while ((pos = line.find('.')) != string::npos) {
            token = line.substr(0, pos);
            tagNames.push_back(token);
            line.erase(0, pos + 1);
        }
        tagNames.push_back(line);
        
        //access the attribute, and print!
        Tag *curTag = &masterTag;
        for (int j = 0; j < tagNames.size(); j++) {
            map<string, Tag *>::iterator it;
            it = curTag->childTags.find(tagNames[j]);
            if (it != curTag->childTags.end()) {
                curTag = it->second;
            } else {
                curTag = NULL;
                break;
            }
        }
        
        if (curTag != NULL) {
            map<string, string>::iterator it = curTag->attrs.find(attr);
            if (it != curTag->attrs.end()) {
                cout << it->second << endl;
            } else {
                //cout << "Not Found!" << curTag->name << "~" << attr << endl;
                cout << "Not Found!" << endl;
            }
        } else {
            //cout << "Not Found!" << tagNames[tagNames.size()-1] << " is null" << endl;
            cout << "Not Found!" << endl;
        }
    }
    return 0;
}
