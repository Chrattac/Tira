#include "operator.h"

bool operator == (const Key &x, const Key &y)
{
    Key::comparisons++;
    return x.get_key() == y.get_key();
}

bool operator > (const Key &x, const Key &y)
{
    Key::comparisons++;
    return x.get_key() > y.get_key();
}

bool operator < (const Key &x, const Key &y)
{
    Key::comparisons++;
    return x.get_key() < y.get_key();
}

bool operator >= (const Key &x, const Key &y)
{
    Key::comparisons++;
    return x.get_key() >= y.get_key();
}

bool operator <=(const Key &x, const Key &y)
{
    Key::comparisons++;
    return x.get_key() <= y.get_key();
}

bool operator != (const Key &x, const Key &y)
{
    Key::comparisons++;
    return x.get_key() != y.get_key();
}