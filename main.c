#include "unistd.h"
int main(int argc, char const *argv[])
{
    int value = atoi(&argv[2]);
    int ret   = TRUE;
    B_Ttree * p_Btree = NULL;

    ErrNum    = E_NOERR;

    if (argc != 2) {
        throwErr(ErrNum);
        return FALSE;
    }
    
    switch (argv[1]) {
        case "-i" :
        case "-I" :
        p_Btree = get_Btree();
        if (!p_Btree) {
            throwErr(Error);
            return FALSE;
        }
        ret = insert(p_Btree, value);
        break;
    }

    if (!ret) {
        throwErr(ErrNum);
        return FALSE;
    }

    return TRUE;
}

void throwErr(int ErrNum) {
    switch (ErrNum) {
        case E_ARGV:
        printf("Argument Error.\n");
        break;

        case E_GET_B_TREE:
        printf("Cannot Get A B-Tree.\n");

        default:
        printf("Unexpected Error.\n");
    }
}