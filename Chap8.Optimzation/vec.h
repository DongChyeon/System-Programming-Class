#ifdef 1
#define OPER +
#define IDENT 0

#else
#define OPER *
#define IDENT 1

typedef int data_t;
typedef struct {
    long len;
    data_t *data;
} vec_rec, *vec_ptr;