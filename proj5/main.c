/*
 * File: main.c
 * Last Modified: 12/01/24
 */

#include <stdio.h>
#include <stdlib.h>
#include "Circuit.h"
#include "BoolCircuits.h"

// function to test the circuits
void testCircuit(Circuit circuit) {
    int numInputs = Circuit_numInputs(circuit);

    printf("%s\n", Circuit_getTitle(circuit));

    if (numInputs == 2) {
        printf("x  y      Result\n");
    } else if (numInputs == 3) {
        printf("x  y  z      Result\n");
    }

    if (numInputs == 2) {
        Circuit_setInput(circuit, 0, 0);
        Circuit_setInput(circuit, 1, 0);
        Circuit_update(circuit);
        printf("0  0  ->  %d\n", Boolean_getValue(Circuit_getOutput(circuit, 0)));

        Circuit_setInput(circuit, 0, 0);
        Circuit_setInput(circuit, 1, 1);
        Circuit_update(circuit);
        printf("0  1  ->  %d\n", Boolean_getValue(Circuit_getOutput(circuit, 0)));

        Circuit_setInput(circuit, 0, 1);
        Circuit_setInput(circuit, 1, 0);
        Circuit_update(circuit);
        printf("1  0  ->  %d\n", Boolean_getValue(Circuit_getOutput(circuit, 0)));

        Circuit_setInput(circuit, 0, 1);
        Circuit_setInput(circuit, 1, 1);
        Circuit_update(circuit);
        printf("1  1  ->  %d\n", Boolean_getValue(Circuit_getOutput(circuit, 0)));
    } else if (numInputs == 3) {
        for (int a = 0; a <= 1; a++) {
            for (int b = 0; b <= 1; b++) {
                for (int c = 0; c <= 1; c++) {
                    Circuit_setInput(circuit, 0, a);
                    Circuit_setInput(circuit, 1, b);
                    Circuit_setInput(circuit, 2, c);
                    Circuit_update(circuit);
                    printf("%d  %d  %d  ->  %d\n", a, b, c, Boolean_getValue(Circuit_getOutput(circuit, 0)));
                }
            }
        }
    }
}

int main(int argc, char **argv) {

    // Testing Circuit A
    printf("\nTESTING CIRCUIT A... \n");
    Circuit circuitA = circuit_a(); 
    testCircuit(circuitA);          
    free_Circuit(circuitA);         

    // Testing Circuit B
    printf("\nTESTING CIRCUIT B... \n");
    Circuit circuitB = circuit_b();
    testCircuit(circuitB);
    free_Circuit(circuitB);

    // Testing Circuit C
    printf("\nTESTING CIRCUIT C... \n");
    Circuit circuitC = circuit_c();
    testCircuit(circuitC);
    free_Circuit(circuitC);

    return 0;
}


