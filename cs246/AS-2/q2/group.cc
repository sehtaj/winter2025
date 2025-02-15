#include "group.h"
using namespace std;


Group::EmailNode::EmailNode(const string &email): email(email), next(nullptr) {}

Group::EmailNode::~EmailNode() {}

Group::GroupNode::GroupNode(Group *group): subgroup(group), next(nullptr) {}

Group::GroupNode::~GroupNode() {}

Group::Group(const string &name) : name(name), emails(nullptr), subgroups(nullptr) {}

Group::~Group() {
    deleteEmails();
    deleteGroups();
}

void Group::deleteEmails() {
    while (emails) {
        EmailNode *temp = emails;
        emails = emails->next;
        delete temp;
    }
}

void Group::deleteGroups() {
    while (subgroups) {
        GroupNode *temp = subgroups;
        subgroups = subgroups->next;
        delete temp->subgroup;
        delete temp;
    }
}

std::string Group::getName() const {
    return name;
}

std::string Group::getEmails() const {
    std::string result;
    for (EmailNode *curr = emails; curr; curr = curr->next) {
        result += curr->email + "\n";
    }
    return result.empty() ? "(no emails)" : result;
}

void Group::addAddress(const string &email) {
    if (!emails || email < emails->email) {
        emails = new EmailNode(email);
        return;
    }

    EmailNode *curr = emails;
    while (curr->next && email >= curr->next->email) {
        curr = curr->next;
    }
    curr->next = new EmailNode(email);
}

void Group::addGroup(Group *group) {
    if (!subgroups || group->getName() < subgroups->subgroup->getName()) {
        subgroups = new GroupNode(group);
        return;
    }

    GroupNode *curr = subgroups;
    while (curr->next && group->getName() >= curr->next->subgroup->getName()) {
        curr = curr->next;
    }
    curr->next = new GroupNode(group);
}

Group::EmailNode *Group::findAddress(const string &email) {
    for (EmailNode *curr = emails; curr; curr = curr->next) {
        if (curr->email == email){
            return curr;
        }
    }

    for (GroupNode *curr = subgroups; curr; curr = curr->next) {
        EmailNode *found = curr->subgroup->findAddress(email);
        if (found){
            return found;
        } 
    }
}

Group::GroupNode *Group::findGroup(const string &name) {
    for (GroupNode *curr = subgroups; curr; curr = curr->next) {
        if (curr->subgroup->getName() == name){
            return curr;
        }
        GroupNode *found = curr->subgroup->findGroup(name);
        if (found) {
            return found;
        }
    }
}

bool Group::removeAddress(const string &email) {
    EmailNode **curr = &emails;
    while (*curr) {
        if ((*curr)->email == email) {
            EmailNode *temp = *curr;
            *curr = (*curr)->next;
            delete temp;
            return true;
        }
        curr = &((*curr)->next);
    }
    return false;
}

bool Group::removeGroup(const string &name) {
    GroupNode **curr = &subgroups;
    while (*curr) {
        if ((*curr)->subgroup->getName() == name) {
            GroupNode *temp = *curr;
            *curr = (*curr)->next;
            delete temp->subgroup;
            delete temp;
            return true;
        }
        curr = &((*curr)->next);
    }
    return false;
}

ostream &operator<<(ostream &out, const Group &group) {
    out << group.getName() << endl;

    if (!group.emails && !group.subgroups) {
        out << "  (empty group)" << endl;
    }

    for (Group::EmailNode *email = group.emails; email; email = email->next) {
        out << "  " << email->email << endl;
    }

    for (Group::GroupNode *sub = group.subgroups; sub; sub = sub->next) {
        out << *(sub->subgroup);
    }

    return out;
}