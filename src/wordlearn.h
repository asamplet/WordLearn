#ifndef WORDLEARN_H
#define WORDLEARN_H

struct d {
    char en[15];
    char ru[15];
};

typedef struct d s2;

void Voc(s2* w);
void Voc1(s2* w);

void Learn(s2* w);
void Learn1(s2* w);

void Wl(s2* w);

#endif
