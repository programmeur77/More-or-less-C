#ifndef FUNCTIONS_H

#define FUNCTIONS_H

void choiceLevel();

void generateNumber(int choice, int min, int max, int level);

void game(int mysteryNumber, int min, int max,int level);

int strokesCount(int *strokes);

void checkRecord(int strokes, int level);

void saveRecord(int *record, int level);

int goon(int *startAgain);

#endif
