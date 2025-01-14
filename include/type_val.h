#ifndef __TYPE_VAL_H__
#define __TYPE_VAL_H__

// For multiple types of data structures
typedef union type_val {
    int i;
    float f;
    char c;
    void *p;
} stype_val;

#endif
