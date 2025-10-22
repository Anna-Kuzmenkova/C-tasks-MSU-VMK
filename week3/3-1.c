STYPE
bit_reverse(STYPE value)
{
    UTYPE uvalue = (UTYPE) value;
    UTYPE revers = 0;
    UTYPE end_flag = ~0;
    while (end_flag) {
        revers <<= 1;
        revers |= uvalue & 1;
        uvalue >>= 1;
        end_flag <<= 1;
    }
    revers = (STYPE) revers;
    return revers;
}
