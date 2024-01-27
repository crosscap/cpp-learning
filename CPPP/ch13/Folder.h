#ifndef FOLDER_H
#define FOLDER_H
#include "Message.h"

class Message;

class Folder
{
	friend class Message;
	friend void swap(Folder &, Folder &);

public:
	Folder() {}
	Folder(const Folder &);
	~Folder();

	Folder &operator=(const Folder &rhs);

	void save(Message &);
	void remove(Message &);

	void addMsg(Message *);
	void remMsg(Message *);

private:
	void add_to_Messages(const Folder &);
	void remove_from_Messages();

	std::set<Message *> messages;
};

#endif