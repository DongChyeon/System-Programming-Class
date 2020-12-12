/* combine.c : combine function tes program. by donghyeon */
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

typedef long data_t;
// typedef float data_t;

#define CONFIG_FOR_ADD
#ifdef CONFIG_FOR_ADD
#define OPER +
#define IDENT 0
#else
#define OPER *
#define IDENT 1
#endif

typedef struct {
    int len;
    data_t *data;
} vec_rec, *vec_ptr;

vec_ptr new_vec(int len);
int get_vec_element(vec_ptr v, long index, data_t *dest);
long vec_length(vec_ptr v);
void combine1(vec_ptr v, data_t *dest);
void combine2(vec_ptr v, data_t *dest);
void combine3(vec_ptr v, data_t *dest);
void combine4(vec_ptr v, data_t *dest);
void combine5(vec_ptr v, data_t *dest);
void combine6(vec_ptr v, data_t *dest);
void combine7(vec_ptr v, data_t *dest);

int main(int argc, char *argv[]) {
    int i, choice = 1, loop = 0;
    struct timeval stime, etime, gap;
    vec_ptr instance;
    data_t result = 0;
    void (*func_ptr) (vec_ptr, data_t *);

    if (argc != 3) {
        printf("Usage : combine number loop_size\n");
        return -1;
    }
    choice = atoi(argv[1]);
    loop = atoi(argv[2]);
    switch(choice) {
        case 1:
            func_ptr = combine1;
            break;
        case 2:
            func_ptr = combine2;
            break;
        case 3:
            func_ptr = combine3;
            break;
        case 4:
            func_ptr = combine4;
            break;
        case 5:
            func_ptr = combine5;
            break;
        case 6:
            func_ptr = combine6;
            break;
	case 7:
	    func_ptr = combine7;
	    break;
        default:
            printf("Choose the number from 1 to 6\n");
	    exit(0);
	    break;
    }

    instance = new_vec(loop);
    for (i = 0; i < vec_length(instance); i++) {
        instance->data[i] = i + 1;
    }
    gettimeofday(&stime, NULL);
    func_ptr(instance, &result);
    gettimeofday(&etime, NULL);
    gap.tv_sec = etime.tv_sec - stime.tv_sec;
    gap.tv_usec = ((etime.tv_sec - stime.tv_sec)*1000000 + etime.tv_usec - stime.tv_usec) % 1000000;
    if (gap.tv_usec < 0) gap.tv_sec = gap.tv_sec - 1;
    printf("Elapsed time %ldsec : %ldusec\n", gap.tv_sec, gap.tv_usec); 
}

vec_ptr new_vec(int len) {
    vec_ptr result = (vec_ptr) malloc(sizeof(vec_rec));
    data_t *data = NULL;
    if (!result) 
        return NULL;
    result->len = len;

    if (len > 0) {
        data = (data_t *) calloc(len, sizeof(data_t));
        if (!data) {
            free((void*) result);
            return NULL;
        }
    }
    result->data = data;
    return result;
}

int get_vec_element(vec_ptr v, long index, data_t *dest) {
    if (index < 0 || index >= v->len)
        return 0;
    *dest = v->data[index];
    return 1;
}

long vec_length(vec_ptr v) {
    return v->len;
}

void combine1(vec_ptr v, data_t *dest) {
    int i;

    *dest = IDENT;
    for (i = 0; i < vec_length(v); i++) {
        data_t val;
        get_vec_element(v, i, &val);
        *dest = *dest OPER val;
    }
}

void combine2(vec_ptr v, data_t *dest) {
    int i;
    int length = vec_length(v);

    *dest = IDENT;
    for (i = 0; i < length; i++) {
        data_t val;
        get_vec_element(v, i, &val);
        *dest = *dest OPER val;
    }
}

data_t *get_vec_start(vec_ptr v) {
    return v->data;
}

void combine3(vec_ptr v, data_t *dest) {
    int i;
    int length = vec_length(v);
    data_t *data = get_vec_start(v);

    *dest = IDENT;
    for (i = 0; i < length; i++) {
        *dest = *dest OPER data[i];
    }
}

void combine4(vec_ptr v, data_t *dest) {
    int i;
    int length = vec_length(v);
    data_t *data = get_vec_start(v);
    data_t x = IDENT;

    for (i = 0; i < length; i++) {
        x = x OPER data[i];
    }
    *dest = x;
}

void combine5(vec_ptr v, data_t *dest) {
    int i;
    int length = vec_length(v);
    data_t *data = get_vec_start(v);
    data_t x = IDENT;
    int limit = length - 2;

    for (i = 0; i < limit; i += 3) {
        x = x OPER data[i] OPER data[i+1] OPER data[i+2];
    }

    for (; i < length; i++) {
        x = x OPER data[i];
    }
    *dest = x;
}

void combine6(vec_ptr v, data_t *dest) {
    int i;
    int length = vec_length(v);
    int limit = length - 1;
    data_t *data = get_vec_start(v);
    data_t x0 = IDENT;
    data_t x1 = IDENT;

    for (i = 0; i < limit; i += 2) {
        x0 = x0 OPER data[i];
        x1 = x1 OPER data[i+1];       
    }
    for (; i < length; i++) {
        x0 = x0 OPER data[i];
    }
    *dest = x0 OPER x1;
}

void combine7(vec_ptr v, data_t *dest) {
    int i;
    int length = vec_length(v);
    int limit = length - 1;
    data_t *data = get_vec_start(v);
    data_t x0 = IDENT;
    data_t x1 = IDENT;
    data_t x2 = IDENT;

    for (i = 0; i < limit; i += 9) {
        x0 = x0 OPER data[i] OPER data[i+1] OPER data[i+2];
        x1 = x1 OPER data[i+3] OPER data[i+4] OPER data[i+5];
        x1 = x2 OPER data[i+6] OPER data[i+7] OPER data[i+8];
    }
    for (; i < length; i++) {
        x0 = x0 OPER data[i];
    }
    *dest = x0 OPER x1 OPER x2;
}
