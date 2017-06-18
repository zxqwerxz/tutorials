/**
 * This example writes a dataset to a new HDF5 file.
 *
 * Compile using:
 *    h5c++ -o create create.cpp
 */

#include <iostream>
#include <string>
#include "H5Cpp.h"
using namespace H5;

const H5std_string FILE_NAME("h5utr_dset.h5");
const H5std_string DATASET_NAME("dset");
const int NX = 4;
const int NY = 6;
const int RANK = 2;

int main() {
  try {
    // Turn off exception auto-printing
    Exception::dontPrint();

    // Create a new file using defaults
    H5File file(FILE_NAME, H5F_ACC_TRUNC);

    // Define size of array and create data space
    hsize_t dims[2]; // 2 dimensions
    dims[0] = NX;
    dims[1] = NY;
    DataSpace dataspace(RANK, dims);

    // Create the dataset
    DataSet dataset = file.createDataSet(DATASET_NAME, PredType::STD_I32BE, dataspace);
  }

  catch(FileIException error) {
    error.printError();
    return -1;
  }

  catch(DataSpaceIException error) {
    error.printError();
    return -1;
  }

  catch(DataSetIException error) {
    error.printError();
    return -1;
  }

  return 0;
}
