typedef int key;
typedef int Record;

class Key{
public:
private:
};

bool operator==(const Key &x, const Key &y);
bool operator> (const Key &x, const Key &y);
bool operator< (const Key &x, const Key &y);
bool operator>=(const Key &x, const Key &y);
bool operator<=(const Key &x, const Key &y);
bool operator!=(const Key &x, const Key &y);

class Record{
public:
	operator Key();
private:
};
