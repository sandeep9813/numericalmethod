 #include <stdio.h>
#include <math.h>

#define SIZE_X 4  
#define SIZE_Y 4  
#define DX 0.05  
#define DY 0.05   
#define EPSILON 0.0001

 
void calculateInteriorNodes(float T[SIZE_X][SIZE_Y]) {
    float prev_T[SIZE_X][SIZE_Y];
    float diff;
    
    
    for (int i = 0; i < SIZE_X; i++) {
        for (int j = 0; j < SIZE_Y; j++) {
            T[i][j] = 0.0;
            prev_T[i][j] = 0.0;
        }
    }

     
    for (int i = 0; i < SIZE_X; i++) {
        T[i][0] = 0.0;      
        T[i][SIZE_Y-1] = 0.0; 
    }
    for (int j = 0; j < SIZE_Y; j++) {
        T[0][j] = 100.0;   
        T[SIZE_X-1][j] = 100.0; 
    }

 
    do {
        
        for (int i = 0; i < SIZE_X; i++) {
            for (int j = 0; j < SIZE_Y; j++) {
                prev_T[i][j] = T[i][j];
            }
        }
 
        for (int i = 1; i < SIZE_X - 1; i++) {
            for (int j = 1; j < SIZE_Y - 1; j++) {
                T[i][j] = 0.25 * (T[i-1][j] + T[i+1][j] + T[i][j-1] + T[i][j+1]);
            }
        }

        
        diff = 0.0;
        for (int i = 0; i < SIZE_X; i++) {
            for (int j = 0; j < SIZE_Y; j++) {
                float d = fabs(T[i][j] - prev_T[i][j]);
                if (d > diff) {
                    diff = d;
                }
            }
        }
    } while (diff > EPSILON);
}

 
void printTemperatureGrid(float T[SIZE_X][SIZE_Y]) {
    for (int i = 0; i < SIZE_X; i++) {
        for (int j = 0; j < SIZE_Y; j++) {
            printf("%.2f\t", T[i][j]);
        }
        printf("\n");
    }
}

int main() {
   
    float T[SIZE_X][SIZE_Y];

    
    calculateInteriorNodes(T);

   
    printf("Temperature Grid (Steady State):\n");
    printTemperatureGrid(T);

    return 0;
}
