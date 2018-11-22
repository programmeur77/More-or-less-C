#ifndef FUNCTIONS_H

#define FUNCTIONS_H

void choiceLevel();

void generateNumber(int choice, int min, int max);

void game(int mysteryNumber, int min, int max);

int strokesCount(int *strokes);

void checkRecord(int strokes);

void saveRecord(int *record);

int goon(int *startAgain);

#endif
