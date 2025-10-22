enum
{
    MY_INT_MAX = ~0u >> -~0
};
enum
{
    MY_INT_MIN = ~MY_INT_MAX
};

int
satsum(int v1, int v2)
{

    int result;
    if (v1 > 0 && v2 > 0 && v1 > MY_INT_MAX - v2) {
        result = MY_INT_MAX;
    } else if (v1 < 0 && v2 < 0 && v1 < MY_INT_MIN - v2) {
        result = MY_INT_MIN;
    } else {
        result = v1 + v2;
    }
    return result;
}
