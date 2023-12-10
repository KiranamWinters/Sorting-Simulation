#include <raylib.h>

#define SCREENWIDTH 1920
#define SCREENHEIGHT 1200
#define WINDOW_NAME "Raylib Window"
#define FRAMERATE 90
#define UPDATEDELAY 0.1

#define BARWIDTH 10
#define GAP 5
#define SIZE 125

static int index = 0;


void InitArrayRandom(int *array, int size, int min, int max){
    for(int i = 0; i < size; i++){
        array[i] = GetRandomValue(min,max);
    }
}

void SingleIterationBubbleSort(int* array, int size){
    int temp;
    for (int i = 0; i+1 < size; i++){
        if (array[i+1] < array[i]){
            temp = array[i];
            array[i] = array[i+1];
            array[i+1] = temp;
        }
    }
}

int main(void){
    
	InitWindow(SCREENWIDTH,SCREENHEIGHT,WINDOW_NAME);
	SetTargetFPS(FRAMERATE);
	ToggleFullscreen();
    int array[SIZE];
    InitArrayRandom(array,SIZE,50, 500);

    while(!WindowShouldClose()){

        if(IsKeyDown(KEY_ESCAPE)){
            CloseWindow();
        }

        BeginDrawing();
        WaitTime(UPDATEDELAY);
        SingleIterationBubbleSort(array,SIZE);
        //SingleIterationSelectionSort(array,SIZE);
        WaitTime(UPDATEDELAY);
        
        for(int i = 0; i < SIZE; i++){
            DrawRectangle((i+1)*(BARWIDTH + GAP), 1000 - array[i], BARWIDTH, array[i], WHITE);
        }

        DrawText("Sorting",100,100,100,WHITE);
        ClearBackground(BLACK);

        EndDrawing();
    }

	CloseWindow();
	return 0;
}
