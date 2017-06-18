// Compile with: h5c++ -std=c++11 testread.cpp

#include <iostream>
#include <string>
#include <unordered_map>
#include "H5Cpp.h"
using namespace H5;
using std::cout;
using std::endl;

const H5std_string FILE_NAME("molecule_info.h5");
const H5std_string DATASET_NAME("barcode");

int main() {
  // Output buffer initialization
  unsigned long long data_out[10000000];
  for (unsigned long i = 0; i < 10000000; i++) {
    data_out[i] = 0;
  }

  try {
    //Exception::dontPrint();

    H5File file(FILE_NAME, H5F_ACC_RDONLY);
    DataSet dataset = file.openDataSet(DATASET_NAME);

    H5T_class_t type_class = dataset.getTypeClass();

    if (type_class == H5T_INTEGER) {
      cout << "Data set has INTEGER type" << endl;
      IntType intype = dataset.getIntType();

      // Get order of the datatype and print
      H5std_string order_string;
      H5T_order_t order = intype.getOrder(order_string);
      cout << order_string << endl;

      // Get size of the data element stored in the file
      size_t size = intype.getSize();
      cout << "Data size is " << size << endl;
    }

    // Get the dataspace of the dataset
    DataSpace dataspace = dataset.getSpace();

    // Get number of dimensions in dataspace
    int rank = dataspace.getSimpleExtentNdims();
    cout << rank << endl; // 1

    /*
    // Get dimension size for each dimension
    hsize_t dims_out[1];
    int ndims = dataspace.getSimpleExtentDims(dims_out, NULL);
    cout << (unsigned long)(dims_out[0]) << endl; // 73741922

    // Define hyperslab in dataset
    hsize_t offset[1] = {0};
    hsize_t count[1] = {1000000};
    dataspace.selectHyperslab(H5S_SELECT_SET, count, offset);

    // Define the memory dataspace
    hsize_t dims_mem[1] = {1000000};
    DataSpace memspace(1, dims_mem);

    // Read data
    cout << "start reading" << endl;
    dataset.read(data_out, PredType::NATIVE_ULLONG, memspace, dataspace);
    cout << "done reading" << endl;

    // Draw record map

    std::unordered_map<unsigned long long, int> recordMap;
    for (unsigned long i = 0; i < 10000000; i++) {
      unsigned long long value = data_out[i];
      if(recordMap.find(value) != recordMap.end()) {
        // Element is found
        recordMap[value] = recordMap[value] + 1;
      } else {
        // Elemnt is not found
        recordMap.insert({value, 1});
      }
    }

    // Print record map
    for (std::pair<unsigned long long, int> element : recordMap) {
      cout << element.first << " :: " << element.second << endl;
    }
    */
  }
  catch( FileIException error ) {
     error.printError();
     return -1;
  }
  catch( DataSetIException error ) {
     error.printError();
     return -1;
  }
  catch( DataSpaceIException error ) {
     error.printError();
     return -1;
  }
  catch( DataTypeIException error ) {
     error.printError();
     return -1;
  }

  return 0;
}
