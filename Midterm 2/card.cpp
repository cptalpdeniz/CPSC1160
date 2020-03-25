/*
* Midterm 2
* Author: Alp Deniz Senyurt
* Student ID: 100342433
* Self explanatory variables and parameters will not be commented as they are, "self-explanatory".
*/

#include "card.h"

// last card on top
// removed using namespace std statement because its cancer lmao

std::ostream &operator<<(std::ostream &out, card const &c) 
{
	out << c.value << (c.c == colour::black ? 'B' : 'R');
	return out;
}

std::ostream &operator<<(std::ostream &out, std::vector<card> const &cs) 
{
	out << "[";
	for (card c : cs) {
		out << " " << c;
	}
	return out << " ]";
}

std::ostream &operator<<(std::ostream &out, pile const &p) 
{
	return out << p.face_down << "," << p.face_up;
}

pile::pile(card const *fd_cards, size_t num_fd_cards, card const *fu_cards, size_t num_fu_cards)
{
	for (size_t i = 0; i < num_fd_cards; ++i)
	{
		face_down.push_back(fd_cards[i]);
	}
	for (size_t i = 0; i < num_fu_cards; ++i)
	{
		face_up.push_back(fu_cards[i]);
	}
}

bool pile::can_add_card(card const &c) const
{
	return (c.value == face_up[face_up.size() - 1].value - 1) && (face_up[face_up.size() -1].c != c.c);
}

pile &pile::operator+=(card const &c)
{
	face_up.push_back(c);
	return *this;
}

pile pile::operator+(card const &c) const
{
	pile tempPile = *this;

	tempPile += c;
	return tempPile;
}

bool pile::can_remove() const
{
	return (static_cast<int>(face_up.size()) == 1) && (!face_down.empty());
}

card pile::remove_top()
{
	card tempCard = face_down[face_down.size() -1];
	card returnCard = face_up[face_up.size() - 1];
	face_up.pop_back();
	face_down.pop_back();
	face_up.push_back(tempCard);

	return returnCard;
}