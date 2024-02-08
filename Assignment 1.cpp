// Assignment 1 

// Program to calculate transition energy using simple Bohr formula

#include<iostream>
#include<iomanip>
#include<limits>
#include<cmath>

bool check_integer (double number)
{
  if (static_cast<int>(number)== number)
  {
    return true;
  }
  else 
  {
    return false;
  }
}

bool check_positive (double number)
{
  if (number >= 1)
  {
    return true;
  }
  else 
  {
    return false;
  }
}

bool verify_input (double number)
{
  if (std::cin.fail()) 
  {
    std::cout<<"Sorry, your input was a string. "<<std::endl; 
    std::cin.clear(); 
    std::cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');  
    return false;
  }
//  else if (std::cin.peek() != '\n')
//  {
//     std::cout <<"Sorry, it looks more than 1 input have been provided. It maybe because you inputted the value with a space. Please input the value without a space "<<std::endl;
//     std::cin.clear(); 
//     std::cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
//     return false;
//  }
  else if (!check_positive(number))
  {
    std::cout<<"Sorry, your input was a negative number."<<std::endl;
    return false;
  }

  else if (!check_integer(number))
  {
    std::cout<<"Sorry your input was a decimal."<<std::endl;
    return false;
  }
  else 
  {
    return true;
  }
}

int input_ni ()
{
  double ni;
  std::cout<<"Enter the initial energy level: "<<std::endl;
  std::cin >> ni;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  while (verify_input (ni) == false)
  {
    std::cout << "Enter a valid positive integer for the initial energy level: " << std::endl;
    std::cin >> ni;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }
std::cout<<"The inputted initial energy level is: "<< ni <<std::endl;
return static_cast<int>(ni);
}

int input_nj (int ni)
{
  double nj; 
  std::cout<<"Enter the final energy level: "<<std::endl;
  std::cin >> nj;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  while (verify_input (nj) == false or ni < nj)
  {
    std::cout << "Enter a valid positive integer for the final energy energy level lower than the initial energy level: " << std::endl;
    std::cin >> nj;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }
  std::cout<<"The inputted final energy level is: "<< nj <<std::endl;
return static_cast<int>(nj);
}

int input_atomic_number ()
{
  double atomic_number; 
  std::cout<<"Enter the atomic number of the atom: "<<std::endl;
  std::cin >> atomic_number;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  while (verify_input (atomic_number) == false or atomic_number >= 118)
  {
    std::cout << "Enter a valid positive integer between 1 and 118 for the atomic number of the atom: " << std::endl;
    std::cin >> atomic_number;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }
  std::cout<<"The inputted atomic number is: "<< atomic_number<<std::endl;
return static_cast<int>(atomic_number);
}

double calculate_transition_energy (int ni, int nj, int z)
{
  return 13.6*z*z*(pow (nj,-2)- pow(ni,-2));
}

void convert_to_joule (double &energy_ev)
{
  const double conversion_factor = 1.60218 * pow (10, -19);
  energy_ev*=conversion_factor;
}

void energy_in_right_units (double& energy_ev)
{
  bool which_unit;
  std::cout <<"Please enter 1 if you want energy in eV and 0 in Joules"<< std::endl;
  std::cin >> which_unit;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  while (std::cin.fail()) 
  {
    std::cout<<"Sorry, your input was not 1 or 0. Enter either 1 if you want in energy in eV or 0 in Joules: "<<std::endl; 
    std::cin.clear(); 
    std::cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');  
    std::cin>> which_unit;
  }
  if (which_unit == 1)
  {
    std::cout << "The calculated transition energy in eV is: " <<energy_ev << std::endl;
  }
  else
  {
    convert_to_joule (energy_ev);
    std::cout << "The calculated transition energy in Joules is: " <<energy_ev << std::endl;
  }
}

int main ()
{
  //bool repeat = true;
  //do
  //{
  int atomic_number = input_atomic_number();
  int ni = input_ni();
  int nj = input_nj(ni);
  double transition_energy_ev = calculate_transition_energy (ni, nj, atomic_number);
  energy_in_right_units (transition_energy_ev);
    //}
    //while (repeat);
  return 0;
}