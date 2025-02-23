/*
 * File: BoolCircuits.c
 */

#include <stdio.h>
#include <stdlib.h>
#include "Circuit.h"
#include "Gates.h"


// function to create Circuit (a)
Circuit circuit_a() {
    char *title = "Circuit (a):";

    int NINPUTS = 2;
    Boolean x = new_Boolean(false);
    Boolean y = new_Boolean(false);
    Boolean* inputs = new_Boolean_array(NINPUTS);
    inputs[0] = x;
    inputs[1] = y;

    int NOUTPUTS = 1;
    Boolean result = new_Boolean(false);
    Boolean* outputs = new_Boolean_array(NOUTPUTS);
    outputs[0] = result;

    // gates
    int NGATES = 4;
    Gate andGate = new_AndGate();         //  x AND y
    Gate notGate = new_Inverter();        //  NOT(x AND y)
    Gate orGate = new_OrGate();           //  x OR y
    Gate finalAndGate = new_AndGate();    //  (NOT(x AND y)) AND (x OR y)
    Gate* gates = new_Gate_array(NGATES);
    gates[0] = andGate;
    gates[1] = notGate;
    gates[2] = orGate;
    gates[3] = finalAndGate;

    Circuit circuit = new_Circuit(title, NINPUTS, inputs, NOUTPUTS, outputs, NGATES, gates);

    // connect AND gate to inputs
    Circuit_connect(circuit, x, Gate_getInput(andGate, 0)); 
    Circuit_connect(circuit, y, Gate_getInput(andGate, 1)); 

    // connect NOT gate to AND gate output
    Boolean andOutput = Gate_getOutput(andGate);            
    Circuit_connect(circuit, andOutput, Gate_getInput(notGate, 0)); 

    // connect OR gate to inputs
    Circuit_connect(circuit, x, Gate_getInput(orGate, 0)); 
    Circuit_connect(circuit, y, Gate_getInput(orGate, 1)); 

    // connect final AND gate
    Boolean notOutput = Gate_getOutput(notGate);          
    Boolean orOutput = Gate_getOutput(orGate);              
    Circuit_connect(circuit, notOutput, Gate_getInput(finalAndGate, 0)); 
    Circuit_connect(circuit, orOutput, Gate_getInput(finalAndGate, 1));

    // connect final AND gate output to result
    Boolean finalAndOutput = Gate_getOutput(finalAndGate);  
    Circuit_connect(circuit, finalAndOutput, result);       

    return circuit;
}

// function to create Circuit (b)
Circuit circuit_b() {
    char *title = "Circuit (b):";

    int NINPUTS = 3;
    Boolean x = new_Boolean(false);
    Boolean y = new_Boolean(false);
    Boolean z = new_Boolean(false);
    Boolean* inputs = new_Boolean_array(NINPUTS);
    inputs[0] = x;
    inputs[1] = y;
    inputs[2] = z;

    int NOUTPUTS = 1;
    Boolean result = new_Boolean(false);
    Boolean* outputs = new_Boolean_array(NOUTPUTS);
    outputs[0] = result;

    // gates
    int NGATES = 4;
    Gate andGate1 = new_AndGate();  // x AND y
    Gate andGate2 = new_AndGate();  // y AND z
    Gate notGate = new_Inverter();  // NOT(y AND z)
    Gate orGate = new_OrGate();     // (x AND y) and NOT(y AND z)
    Gate* gates = new_Gate_array(NGATES);
    gates[0] = andGate1;
    gates[1] = andGate2;
    gates[2] = notGate;
    gates[3] = orGate;

    Circuit circuit = new_Circuit(title, NINPUTS, inputs, NOUTPUTS, outputs, NGATES, gates);

    // connect inputs to AND gates
    Circuit_connect(circuit, x, Gate_getInput(andGate1, 0)); 
    Circuit_connect(circuit, y, Gate_getInput(andGate1, 1)); 

    Circuit_connect(circuit, y, Gate_getInput(andGate2, 0));
    Circuit_connect(circuit, z, Gate_getInput(andGate2, 1)); 

    // connect NOT gate to output of AND2
    Boolean and2Output = Gate_getOutput(andGate2);         
    Circuit_connect(circuit, and2Output, Gate_getInput(notGate, 0)); 

    // connect OR gate
    Boolean and1Output = Gate_getOutput(andGate1);          
    Boolean notOutput = Gate_getOutput(notGate);            
    Circuit_connect(circuit, and1Output, Gate_getInput(orGate, 0)); 
    Circuit_connect(circuit, notOutput, Gate_getInput(orGate, 1)); 

    // connect OR gate output to result
    Boolean orOutput = Gate_getOutput(orGate);              
    Circuit_connect(circuit, orOutput, result);              

    return circuit;
}

// function to create Circuit (c)
Circuit circuit_c() {
    char *title = "Circuit (c):";

    int NINPUTS = 3;
    Boolean x = new_Boolean(false);
    Boolean y = new_Boolean(false);
    Boolean z = new_Boolean(false);
    Boolean* inputs = new_Boolean_array(NINPUTS);
    inputs[0] = x;
    inputs[1] = y;
    inputs[2] = z;

    int NOUTPUTS = 1;
    Boolean result = new_Boolean(false);
    Boolean* outputs = new_Boolean_array(NOUTPUTS);
    outputs[0] = result;

    // gates
    int NGATES = 8;
    Gate notX = new_Inverter(); // NOT(x)
    Gate notY = new_Inverter(); // NOT(y)
    Gate notZ = new_Inverter(); // NOT(z)
    Gate and1 = new_AndGate();  // AND gate: NOT(y) AND x
    Gate and2 = new_AndGate();  // AND gate: NOT(z) AND y
    Gate and3 = new_AndGate();  // AND gate: NOT(x) AND z
    Gate or1 = new_OrGate();    // OR gate: (NOT(y) AND x) OR (NOT(z) AND y)
    Gate or2 = new_OrGate();    // final OR gate
    Gate* gates = new_Gate_array(NGATES);
    gates[0] = notX;
    gates[1] = notY;
    gates[2] = notZ;
    gates[3] = and1;
    gates[4] = and2;
    gates[5] = and3;
    gates[6] = or1;
    gates[7] = or2;

    Circuit circuit = new_Circuit(title, NINPUTS, inputs, NOUTPUTS, outputs, NGATES, gates);

    // connect inputs to NOT gates
    Circuit_connect(circuit, x, Gate_getInput(notX, 0)); // x -> NOT(x)
    Circuit_connect(circuit, y, Gate_getInput(notY, 0)); // y -> NOT(y)
    Circuit_connect(circuit, z, Gate_getInput(notZ, 0)); // z -> NOT(z)

    // get outputs of NOT gates
    Boolean notXOutput = Gate_getOutput(notX); 
    Boolean notYOutput = Gate_getOutput(notY);
    Boolean notZOutput = Gate_getOutput(notZ); 

    // connect AND gates
    Circuit_connect(circuit, notYOutput, Gate_getInput(and1, 0)); 
    Circuit_connect(circuit, x, Gate_getInput(and1, 1));         

    Circuit_connect(circuit, notZOutput, Gate_getInput(and2, 0)); 
    Circuit_connect(circuit, y, Gate_getInput(and2, 1));          

    Circuit_connect(circuit, notXOutput, Gate_getInput(and3, 0)); 
    Circuit_connect(circuit, z, Gate_getInput(and3, 1));         

    // get outputs of AND gates
    Boolean and1Output = Gate_getOutput(and1); 
    Boolean and2Output = Gate_getOutput(and2); 
    Boolean and3Output = Gate_getOutput(and3); 

    // connect OR gates
    Circuit_connect(circuit, and1Output, Gate_getInput(or1, 0)); 
    Circuit_connect(circuit, and2Output, Gate_getInput(or1, 1)); 

    Boolean or1Output = Gate_getOutput(or1);                     
    Circuit_connect(circuit, or1Output, Gate_getInput(or2, 0));  
    Circuit_connect(circuit, and3Output, Gate_getInput(or2, 1)); 

    // connect OR2 output to the result
    Boolean or2Output = Gate_getOutput(or2);                    
    Circuit_connect(circuit, or2Output, result);                

    return circuit;
}
