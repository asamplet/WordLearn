#ifndef WORDLEARN_H
#define WORDLEARN_H
#define n 30
struct d {
    char en[15];
    char ru[15];
};

typedef struct d s2;

void Voc(s2* w, int S[n]);
void Voc1(s2* w, int B[n]);

void Learn(s2* w);
void Learn1(s2* w);

void Wl(s2* w);

#endif
