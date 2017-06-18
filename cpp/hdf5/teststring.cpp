#include <iostream>
#include <string>
#include "H5Cpp.h"
using namespace H5;
using std::cout;
using std::cerr;
using std::endl;

const H5std_string FILE_NAME("string_test.h5");
const H5std_string DS_NAME("Data Set 1");
const H5std_string ATTR_NAME("String Attribute");

int main() {
  H5File file = H5File(FILE_NAME, H5F_ACC_TRUNC);

  hsize_t dims[3] = {2, 2, 2};
  DataSpace dataspace = DataSpace(3, dims);
  FloatType datatype(PredType::NATIVE_FLOAT);
  DataSet dataset = file.createDataSet(DS_NAME, datatype, dataspace);

  // Set up write buffer
  int q, r, s;
  float value;
  float matrix[2][2][2];
  for (q = 0; q < 2; q++) {
    for (r = 0; r < 2; r++) {
      for (s = 0; s < 2; s++) {
        value = 1.111 + (q * r * s);
        matrix[q][r][s] = value;
      }
    }
  }

  // Write data to dataset
  dataset.write(matrix, datatype);

  // Create new dataspace for Attribute
  DataSpace attr_dataspace = DataSpace(H5S_SCALAR);
  StrType strdatatype(PredType::C_S1, 256);
  const H5std_string strwritebuf("This is the string to write");
  Attribute myatt_in = dataset.createAttribute(ATTR_NAME, strdatatype, attr_dataspace);
  myatt_in.write(strdatatype, strwritebuf);

  // Set up read buffer
  H5std_string strreadbuf("");
  Attribute myatt_out = dataset.openAttribute(ATTR_NAME);
  myatt_out.read(strdatatype, strreadbuf);

  cout << "Attribute contents: " << strreadbuf << endl;

}
