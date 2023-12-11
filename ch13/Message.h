#ifndef MESSAGE_H
#define MESSAGE_H

#include <iostream>
#include <set>
#include <string>

#include "Folder.h"

class Folder;

class Message
{
	friend class Folder;
    friend void swap(Message &, Message &);

public:
	explicit Message(const std::string &str = "")
		: contents(str) {}
	Message(const Message &);
	~Message();

	Message &operator=(const Message &);

	void save(Folder &);
	void remove(Folder &);

	void addFldr(Folder *);
	void remFldr(Folder *);

private:
	std::string contents;
	std::set<Folder *> folders;

	void add_to_Folders(const Message &);
	void remove_from_Folders();
};

#endif