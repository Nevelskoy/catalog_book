#pragma once
#include "book.h"

struct CARD_INDEX {
    BOOK** pB;
    size_t count;
    size_t capacity;
};

void printCatalog(const struct CARD_INDEX* catalog);