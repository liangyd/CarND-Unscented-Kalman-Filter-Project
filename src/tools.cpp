#include <iostream>
#include "tools.h"

using Eigen::VectorXd;
using Eigen::MatrixXd;
using std::vector;

Tools::Tools() {}

Tools::~Tools() {}

VectorXd Tools::CalculateRMSE(const vector<VectorXd> &estimations,
                              const vector<VectorXd> &ground_truth) {
  /**
    * Calculate the RMSE here.
  */
VectorXd rmse(4);
  rmse << 0,0,0,0;

  if(estimations.size()==0||estimations.size()!=ground_truth.size()){
        cout<<"CalculateRMSE()-invalid input"<<endl;
        return rmse;
  }
  //accumulate squared residuals
  VectorXd sub(4);
  sub << 0,0,0,0;
  VectorXd sum(4);
  sum << 0,0,0,0;
  for(int i=0; i < estimations.size(); ++i){
	sub=estimations[i]-ground_truth[i];
	sum=sum.array()+sub.array()*sub.array();
  }

  //calculate the mean
  VectorXd mean(4);
  mean << 0,0,0,0;
  mean=sum/estimations.size();
  //calculate the squared root
  rmse=mean.array().sqrt();
  //return the result
  return rmse;
}
