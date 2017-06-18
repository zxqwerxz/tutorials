#include <iostream>
#include <string>
#include "H5Cpp.h"
using namespace H5;

const H5std_string FILE_NAME("h5utr_dset.h5");
const H5std_string DATASET_NAME("dset");
const int DIM0 = 4;
const int DIM1 = 6;

int main() {
  // initialize data
  int i, j;
  int data[DIM0][DIM1];
  for (j = 0; j < DIM0; j++) {
    for (i = 0; i < DIM1; i++) {
      data[j][i] = i * 6 + j + 1;
    }
  }

  try {
    Exception::dontPrint();

    // Open an existing file and dataset.
    H5File file(FILE_NAME, H5F_ACC_RDWR);
    DataSet dataset = file.openDataSet(DATASET_NAME);

    // Write the data to datset using default memory space
    dataset.write(data, PredType::NATIVE_INT);
  }

  catch(FileIException error) {
  	error.printError();
  	return -1;
  }

  catch(DataSetIException error) {
	  error.printError();
	  return -1;
  }

  return 0;
}
