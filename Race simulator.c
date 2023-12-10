#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structures section
struct Race {
    int numberOfLaps;
    int currentLap;
    char* firstPlaceDriverName;
    char* firstPlaceRaceCarColor;
};
struct RaceCar{
    char driverName[50];
    char raceCarColor[20];
    int totalLapTime;
};
// Print functions section
void printIntro(){
    printf("Welcome to our main event digital race fans!\nI hope everybody has their snacks because we are about to begin!\n");
}
void printCountDown(){
    printf("Racers Ready! in...\n");
    for(int i = 5; i >= 1; i--){
        printf("%d\n", i);
    }
    printf("Race!\n");
}
void printFirstPlaceAfterLap(struct Race* race){
    printf("After lap number %d\nFirst Place Is: %s in the %s race car!\n", race->currentLap, race->firstPlaceDriverName, race->firstPlaceRaceCarColor);
}
void printCongratulation(struct Race* race){
    printf("Lets all congratulate %s in the %s race car for an amazing performance.\nIt truly was a great race abd everyone have a goodnight!\n", race->firstPlaceDriverName, race->firstPlaceRaceCarColor);
}

// Logic functions section
int calculateTimeToCompleteLap(){
    int speed = rand() % 3 + 1;
    int acceleration = rand() % 3 + 1;
    int nerves = rand() % 3 + 1;
    int sum = speed + acceleration + nerves;
    return sum;
}
void updateRaceCar(struct RaceCar* raceCar){
    raceCar->totalLapTime += calculateTimeToCompleteLap();
}
void updateFirstPlace(struct Race* race, struct RaceCar* raceCar1, struct RaceCar* raceCar2){
    if(raceCar1->totalLapTime <= raceCar2->totalLapTime){
        race->firstPlaceDriverName = raceCar1->driverName;
        race->firstPlaceRaceCarColor = raceCar1->raceCarColor;
    }else{
        race->firstPlaceDriverName = raceCar2->driverName;
        race->firstPlaceRaceCarColor = raceCar2->raceCarColor;
    }
}
void startRace(struct RaceCar* raceCar1, struct RaceCar* raceCar2){
    struct Race race = {5,1,"",""};
    for(int lap = 1; lap <= race.numberOfLaps; lap++){
        updateRaceCar(raceCar1);
        updateRaceCar(raceCar2);
        updateFirstPlace(&race, raceCar1, raceCar2);
        race.currentLap = lap;
        printFirstPlaceAfterLap(&race);
    }
    printCongratulation(&race);
}
int main() {
    srand(time(0));
    struct RaceCar raceCar1 = {"Lewis Hamilton", "Red", 0};
    struct RaceCar raceCar2 = {"Sebastian Vettel", "Blue", 0};
    printIntro();
    printCountDown();
    startRace(&raceCar1, &raceCar2);
};