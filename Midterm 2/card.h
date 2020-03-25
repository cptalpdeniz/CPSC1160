/*
* Midterm 2
* Author: Alp Deniz Senyurt
* Student ID: 100342433
* Self explanatory variables and parameters will not be commented as they are, "self-explanatory".
*/

#include <iostream>
#include <vector>

enum class colour
{
	black,
	red
};

struct card 
{
	int value;
	colour c;
};

std::ostream &operator<<(std::ostream &, card const &);
class pile 
{
	std::vector<card> face_down, face_up;
public:
	pile(card const *fd_cards, size_t num_fd_cards, card const *fu_cards, size_t num_fu_cards);
	bool can_add_card(card const &) const;
	pile &operator+=(card const &);
	pile operator+(card const &) const;
	bool can_remove() const;
	card remove_top();
	friend std::ostream &operator<<(std::ostream &, pile const &);
};
