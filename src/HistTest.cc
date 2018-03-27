#include "Histogram.hpp"

void  calHistogram(const std::vector<double> &xVec, std::vector<size_t> &hVec)
{
  size_t bmax=0;
  std::for_each(xVec.begin(), xVec.end(), 
      [&hVec, &bmax](const double &element)
      {
        hVec[element]++;
        bmax=std::max(bmax, hVec[element]);
      });
}

void  calHistogram(const std::vector<double> &xVec, std::unordered_map<double, size_t> &hMap)
{
  size_t bmax=0;
  std::for_each(xVec.begin(), xVec.end(), 
      [&hMap, &bmax](const double &element)
      {
        hMap[element]++;
        bmax=std::max(bmax, hMap[element]);
      });
}

void  calHistogram(const std::vector<double> &xVec, std::map<double, size_t> &hMap)
{
  size_t bmax=0;
  std::for_each(xVec.begin(), xVec.end(), 
      [&hMap, &bmax](const double &element)
      {
        hMap[element]++;
        bmax=std::max(bmax, hMap[element]);
      });
}


std::vector<size_t> getHistogram(const std::vector<double> &xVec, size_t num){
  std::vector<size_t> h(num, 0);
  calHistogram(xVec, h);
  return h;
}


std::unordered_map<double, size_t> sparseHistogram(const std::vector<double>& xVec) {
  std::unordered_map<double, size_t> h;                        // histogram
  calHistogram(xVec, h);
  return h;
}

std::map<double, size_t> orderedSparseHistogram(const std::vector<double>& xVec) {
  std::map<double, size_t> h;                        // histogram
  calHistogram(xVec, h);
  return h;
}

int main(int argc, char* argv[]){
  std::vector<double> xVec(20);

  std::fill(xVec.begin(), xVec.begin()+2, 4.4);
  std::fill(xVec.begin()+3, xVec.end()-10, 5.0);
  std::fill(xVec.end()-9, xVec.end(), 3.1);


  std::vector<size_t> hVec;
  std::vector<size_t>::iterator hItr;
  //hVec.resize(xVec.size(), 0);
  //hVec.resize(100, 0);

  //calHistogram(xVec, hVec);

  //auto h2Vec = getHistogram(xVec, 11);

  auto h3Map = sparseHistogram(xVec);

  //for(hItr=hVec.begin(); hItr!=hVec.end(); hItr++){

  //  std::cout << (*hItr) << std::endl; 

  //}
  
  std::unordered_map<double, size_t>::iterator h3Itr;

  for(h3Itr=h3Map.begin(); h3Itr!=h3Map.end(); h3Itr++){

    std::cout << h3Itr->first <<  "  " << h3Itr->second  << std::endl; 

  }


  auto h4Map = orderedSparseHistogram(xVec);


  for(auto h4Itr : h4Map){

    std::cout << h4Itr.first <<  "  " << h4Itr.second  << std::endl; 

  }


  return 0;
}
