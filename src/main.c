#include <stdio.h>
#include <stdlib.h>
#include "csv_utils.h"

/**
 * void get_nodes_values(float* nodes, double* values, const char* filepath);

 * Reads nodes and values from a CSV file
 * @param nodes Array to store node values
 * @param values Array to store function values
 * @param size Number of nodes to read
 */

/**
 * void add_approximation(float target, double accuracy, int first, double value, double approx, const char* filepath);

 * Adds interpolation results to a CSV file for visualization (not necessary)
 * @param target The x-value (node) being interpolated
 * @param accuracy Error percentage
 * @param first Flag to indicate first entry (header creation)
 * @param value Actual function value
 * @param approx Approximated value from interpolation
 */

// an example function
double interpolationFunction(float* nodes, double* values, float targetNode, int size);

int main(void) {

    int size;
    printf("How many nodes does your program have: ");
    scanf("%d", &size);

    // nodes and values array
    float* nodes = (float *)malloc(size * sizeof(float));
    double* values = (double *)malloc(size * sizeof(double));
    if(nodes == NULL || values == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    /*
     * the 'filepath' parameter for linux:
     *      "../data/nodes_values.csv"
     * 
     * and for windows:
     *      "..\\data\\nodes_values.csv" 
     */

    get_nodes_values(nodes, values, "..\\data\\nodes_values.csv");

    /*
     * You can now use the two arrays above to interpolate any value that fits your given dataset.
    */

    //_______________________________________________________________________________________________________________
    // You code goes here: 

    // example usage

    float checkNode;
    printf("Enter the node whose value you want to interpolate: ");
    scanf("%f", &checkNode);

    double approximate = interpolationFunction(nodes, values, checkNode, size);
    printf("The approximate value at node %.2f is: %.10lf\n", checkNode, approximate);

    return 0;
}

/*
 * function definition goes here
 */

double interpolationFunction(float* nodes, double* values, float targetNode, int size) {

    /*
     * Write function code here
     */

}