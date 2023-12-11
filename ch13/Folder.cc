#include "Folder.h"

Folder::Folder(const Folder &orig)
	: messages(orig.messages)
{
	add_to_Messages(orig);
}

Folder::~Folder()
{
	remove_from_Messages();
}

Folder &Folder::operator=(const Folder &rhs)
{
	remove_from_Messages();
	messages = rhs.messages;
	add_to_Messages(rhs);
	return *this;
}

void Folder::save(Message &msg)
{
	messages.insert(&msg);
	msg.addFldr(this);

}

void Folder::remove(Message &msg)
{
	messages.erase(&msg);
	msg.remFldr(this);
}

void Folder::addMsg(Message *msg)
{
	messages.insert(msg);
}
void Folder::remMsg(Message *msg)
{
	messages.erase(msg);
}

void Folder::add_to_Messages(const Folder &f)
{
	for (auto m : f.messages)
		m->addFldr(this);
}

void Folder::remove_from_Messages()
{
	for (auto m : messages)
		m->remFldr(this);
}

void swap(Folder &lhs, Folder &rhs)
{
	for (auto m : lhs.messages)
		m->remFldr(&lhs);
	for (auto m : rhs.messages)
		m->remFldr(&rhs);
	swap(lhs.messages, rhs.messages);
	for (auto m : lhs.messages)
		m->addFldr(&lhs);
	for (auto m : rhs.messages)
		m->addFldr(&rhs);
}