#ifndef GROUP_H
#define GROUP_H

#include <string>
#include <iostream>

class Group {
private:
    std::string name; 

    class EmailNode;
    class GroupNode;
    EmailNode *emails;  
    GroupNode *subgroups;  
    void deleteEmails();
    void deleteGroups();   

public:
    Group(const std::string &name); 
    ~Group();  

    std::string getName() const;  
    void addAddress(const std::string &email); 
    void addGroup(Group *group); 
    bool removeAddress(const std::string &email); 
    bool removeGroup(const std::string &groupName);
    void print() const; 

    class EmailNode {
    public:
        std::string email;
        EmailNode *emails; 
        EmailNode *next;

        EmailNode(const std::string &email);
        ~EmailNode();
    };
    class GroupNode {
    public:
        Group *subgroup;
        GroupNode *subgroups; 
        GroupNode *next;

        GroupNode(Group *subgroup);
        ~GroupNode();
    };
    friend std::ostream &operator<<(std::ostream &out, const Group &group);
};

#endif