class fraction {
    int num, denom;
public:
    fraction(int n, int d=1) : num(n), denom(d) {}
    void reduce();
    void print() const;
    fraction operator+(fraction const &) const;
    fraction &operator+=(fraction const &);
    fraction operator-() const;
    fraction operator-(fraction const &) const;
    fraction &operator-=(fraction const &);
    bool operator<(fraction const &) const;
};