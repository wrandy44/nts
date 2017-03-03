//
// Component4008.cpp for component4008 in /home/brunel/Rendu/Semestre_3/CPP/cpp_nanotekspice/src
// 
// Made by Brunel Axel
// Login   <axel.brunel@epitech.eu>
// 
// Started on  Thu Mar  2 17:12:30 2017 Brunel Axel
// Last update Fri Mar  3 15:16:35 2017 Brunel Axel
//

#include "ComponentCreator.hpp"

Component4008::Component4008(std::string const &name)
  : Component(name)
{
  _pinLink_t	tmppin;
  _nbPin = 16;
  _type = "Chipset 4008";
  for (unsigned int i = 0; i < _nbPin; i++)
    {
      tmppin._pin = nts::UNDEFINED;
      _pin.push_back(tmppin);
    }
  _pin[0]._type = PIN_IN;
  _pin[1]._type = PIN_IN;
  _pin[2]._type = PIN_IN;
  _pin[3]._type = PIN_IN;
  _pin[4]._type = PIN_IN;
  _pin[5]._type = PIN_IN;
  _pin[6]._type = PIN_IN;
  _pin[7]._type = PIN_UNDEF;
  _pin[8]._type = PIN_IN;
  _pin[9]._type = PIN_OUT;
  _pin[10]._type = PIN_OUT;
  _pin[11]._type = PIN_OUT;
  _pin[12]._type = PIN_OUT;
  _pin[13]._type = PIN_OUT;
  _pin[14]._type = PIN_IN;
  _pin[15]._type = PIN_UNDEF;
}

Component4008::~Component4008()
{
}

// void		Component4008::output1()
// {
//   if (_pin[6]._pin == nts::FALSE
//       && _pin[5]._pin == nts::FALSE
//       && _pin[8]._pin == nts::FALSE)
//     {
//       _pin[13]._pin == nts::FALSE;
//       _pin[9]._pin = nts::FALSE;
//     }
//   else if (_pin[6]._pin == nts::UNDEFINED
// 	   || _pin[5]._pin == nts::UNDEFINED
// 	   || _pin[8]._pin == nts::UNDEFINED)
//     {
//       _pin[13]._pin == nts::UNDEFINED;
//       _pin[9]._pin = nts::UNDEFINED;
//     }
//   else
//     {
//       _pin[13]._pin = nts::TRUE;
//       _pin[9]._pin = nts::TRUE;
//     }
// }

// void		Component4008::output2()
// {
//   if (_pin[6]._pin == nts::TRUE
//       && _pin[5]._pin == nts::FALSE
//       && _pin[8]._pin == nts::FALSE)
//     {
//       _pin[13]._pin == nts::FALSE;
//       _pin[9]._pin = nts::TRUE;
//     }
//   else if (_pin[6]._pin == nts::UNDEFINED
// 	   || _pin[5]._pin == nts::UNDEFINED
// 	   || _pin[8]._pin == nts::UNDEFINED)
//     {
//       _pin[13]._pin == nts::UNDEFINED;
//       _pin[9]._pin = nts::UNDEFINED;
//     }
//   else
//     {
//       _pin[13]._pin = nts::TRUE;
//       _pin[9]._pin = nts::FALSE;
//     }
// }

// void		Component4008::output3()
// {
//   if (_pin[4]._pin == nts::FALSE
//       && _pin[3]._pin == nts::TRUE
//       && _pin[9]._pin == nts::FALSE)
//     {
//       _pin[13]._pin == nts::FALSE;
//       _pin[10]._pin = nts::TRUE;
//     }
//   else if (_pin[4]._pin == nts::UNDEFINED
// 	   || _pin[3]._pin == nts::UNDEFINED
// 	   || _pin[9]._pin == nts::UNDEFINED)
//     {
//       _pin[13]._pin == nts::UNDEFINED;
//       _pin[10]._pin = nts::UNDEFINED;
//     }
//   else
//     {
//       _pin[13]._pin = nts::TRUE;
//       _pin[10]._pin = nts::FALSE;
//     }
// }

// void		Component4008::output4()
// {
//   if (_pin[4]._pin == nts::TRUE
//       && _pin[3]._pin == nts::TRUE
//       && _pin[9]._pin == nts::FALSE)
//     {
//       _pin[13]._pin == nts::TRUE;
//       _pin[10]._pin = nts::FALSE;
//     }
//   else if (_pin[4]._pin == nts::UNDEFINED
// 	   || _pin[3]._pin == nts::UNDEFINED
// 	   || _pin[9]._pin == nts::UNDEFINED)
//     {
//       _pin[13]._pin == nts::UNDEFINED;
//       _pin[10]._pin = nts::UNDEFINED;
//     }
//   else
//     {
//       _pin[13]._pin = nts::FALSE;
//       _pin[10]._pin = nts::TRUE;
//     }
// }

// void		Component4008::output5()
// {
//   if (_pin[1]._pin == nts::FALSE
//       && _pin[2]._pin == nts::FALSE
//       && _pin[10]._pin == nts::TRUE)
//     {
//       _pin[13]._pin == nts::FALSE;
//       _pin[11]._pin = nts::TRUE;
//     }
//   else if (_pin[1]._pin == nts::UNDEFINED
// 	   || _pin[2]._pin == nts::UNDEFINED
// 	   || _pin[10]._pin == nts::UNDEFINED)
//     {
//       _pin[13]._pin == nts::UNDEFINED;
//       _pin[11]._pin = nts::UNDEFINED;
//     }
//   else
//     {
//       _pin[13]._pin = nts::TRUE;
//       _pin[11]._pin = nts::FALSE;
//     }
// }

// void		Component4008::output6()
// {
//   if (_pin[1]._pin == nts::FALSE
//       && _pin[2]._pin == nts::TRUE
//       && _pin[10]._pin == nts::TRUE)
//     {
//       _pin[13]._pin == nts::TRUE;
//       _pin[11]._pin = nts::FALSE;
//     }
//   else if (_pin[1]._pin == nts::UNDEFINED
// 	   || _pin[2]._pin == nts::UNDEFINED
// 	   || _pin[10]._pin == nts::UNDEFINED)
//     {
//       _pin[13]._pin == nts::UNDEFINED;
//       _pin[11]._pin = nts::UNDEFINED;
//     }
//   else
//     {
//       _pin[13]._pin = nts::FALSE;
//       _pin[11]._pin = nts::TRUE;
//     }
// }

// void		Component4008::output7()
// {
//   if (_pin[0]._pin == nts::FALSE
//       && _pin[14]._pin == nts::TRUE
//       && _pin[11]._pin == nts::TRUE)
//     {
//       _pin[13]._pin == nts::TRUE;
//       _pin[12]._pin = nts::FALSE;
//     }
//   else if (_pin[0]._pin == nts::UNDEFINED
// 	   || _pin[14]._pin == nts::UNDEFINED
// 	   || _pin[11]._pin == nts::UNDEFINED)
//     {
//       _pin[13]._pin == nts::UNDEFINED;
//       _pin[12]._pin = nts::UNDEFINED;
//     }
//   else
//     {
//       _pin[13]._pin = nts::FALSE;
//       _pin[12]._pin = nts::TRUE;
//     }
// }

// void		Component4008::output8()
// {
//   if (_pin[0]._pin == nts::TRUE
//       && _pin[14]._pin == nts::TRUE
//       && _pin[11]._pin == nts::TRUE)
//     {
//       _pin[13]._pin == nts::TRUE;
//       _pin[12]._pin = nts::TRUE;
//     }
//   else if (_pin[0]._pin == nts::UNDEFINED
// 	   || _pin[14]._pin == nts::UNDEFINED
// 	   || _pin[11]._pin == nts::UNDEFINED)
//     {
//       _pin[13]._pin == nts::UNDEFINED;
//       _pin[12]._pin = nts::UNDEFINED;
//     }
//   else
//     {
//       _pin[13]._pin = nts::FALSE;
//       _pin[12]._pin = nts::FALSE;
//     }
// }

void		Component4008::output_1()
{
  if (_pin[6]._pin == nts::FALSE && _pin[5]._pin == nts::FALSE && _pin[8]._pin == nts::FALSE)
    {
      _pin[13]._pin = nts::FALSE;
      _pin[9]._pin = nts::FALSE;
    }
  else if (_pin[6]._pin == nts::TRUE && _pin[5]._pin == nts::FALSE && _pin[8]._pin == nts::FALSE)
    {
      _pin[13]._pin = nts::FALSE;
      _pin[9]._pin = nts::TRUE;
    }
  else if (_pin[6]._pin == nts::FALSE && _pin[5]._pin == nts::TRUE && _pin[8]._pin == nts::FALSE)
    {
      _pin[13]._pin = nts::FALSE;
      _pin[9]._pin = nts::TRUE;
    }
  else if (_pin[6]._pin == nts::TRUE && _pin[5]._pin == nts::TRUE && _pin[8]._pin == nts::FALSE)
    {
      _pin[13]._pin = nts::TRUE;
      _pin[9]._pin = nts::FALSE;
    }
  else if (_pin[6]._pin == nts::FALSE && _pin[5]._pin == nts::FALSE && _pin[8]._pin == nts::TRUE)
    {
      _pin[13]._pin = nts::FALSE;
      _pin[9]._pin = nts::TRUE;
    }
  else if (_pin[6]._pin == nts::TRUE && _pin[5]._pin == nts::FALSE && _pin[8]._pin == nts::TRUE)
    {
      _pin[13]._pin = nts::TRUE;
      _pin[9]._pin = nts::FALSE;
    }
  else if (_pin[6]._pin == nts::FALSE && _pin[5]._pin == nts::TRUE && _pin[8]._pin == nts::TRUE)
    {
      _pin[13]._pin = nts::TRUE;
      _pin[9]._pin = nts::FALSE;
    }
  else if (_pin[6]._pin == nts::TRUE && _pin[5]._pin == nts::TRUE && _pin[8]._pin == nts::TRUE)
    {
      _pin[13]._pin = nts::TRUE;
      _pin[9]._pin = nts::TRUE;
    }
  else if (_pin[6]._pin == nts::UNDEFINED || _pin[5]._pin == nts::UNDEFINED || _pin[8]._pin == nts::UNDEFINED)
    {
      _pin[13]._pin = nts::UNDEFINED;
      _pin[9]._pin = nts::UNDEFINED;
    }
}

void		Component4008::output_2()
{
  if (_pin[4]._pin == nts::FALSE && _pin[3]._pin == nts::FALSE && _pin[9]._pin == nts::FALSE)
    {
      _pin[13]._pin = nts::FALSE;
      _pin[10]._pin = nts::FALSE;
    }
  else if (_pin[4]._pin == nts::TRUE && _pin[3]._pin == nts::FALSE && _pin[9]._pin == nts::FALSE)
    {
      _pin[13]._pin = nts::FALSE;
      _pin[10]._pin = nts::TRUE;
    }
  else if (_pin[4]._pin == nts::FALSE && _pin[3]._pin == nts::TRUE && _pin[9]._pin == nts::FALSE)
    {
      _pin[13]._pin = nts::FALSE;
      _pin[10]._pin = nts::TRUE;
    }
  else if (_pin[4]._pin == nts::TRUE && _pin[3]._pin == nts::TRUE && _pin[9]._pin == nts::FALSE)
    {
      _pin[13]._pin = nts::TRUE;
      _pin[10]._pin = nts::FALSE;
    }
  else if (_pin[4]._pin == nts::FALSE && _pin[3]._pin == nts::FALSE && _pin[9]._pin == nts::TRUE)
    {
      _pin[13]._pin = nts::FALSE;
      _pin[10]._pin = nts::TRUE;
    }
  else if (_pin[4]._pin == nts::TRUE && _pin[3]._pin == nts::FALSE && _pin[9]._pin == nts::TRUE)
    {
      _pin[13]._pin = nts::TRUE;
      _pin[10]._pin = nts::FALSE;
    }
  else if (_pin[4]._pin == nts::FALSE && _pin[3]._pin == nts::TRUE && _pin[9]._pin == nts::TRUE)
    {
      _pin[13]._pin = nts::TRUE;
      _pin[10]._pin = nts::FALSE;
    }
  else if (_pin[4]._pin == nts::TRUE && _pin[3]._pin == nts::TRUE && _pin[9]._pin == nts::TRUE)
    {
      _pin[13]._pin = nts::TRUE;
      _pin[10]._pin = nts::TRUE;
    }
  else if (_pin[4]._pin == nts::UNDEFINED || _pin[3]._pin == nts::UNDEFINED || _pin[9]._pin == nts::UNDEFINED)
    {
      _pin[13]._pin = nts::UNDEFINED;
      _pin[10]._pin = nts::UNDEFINED;
    }
}

void		Component4008::output_3()
{
  if (_pin[2]._pin == nts::FALSE && _pin[1]._pin == nts::FALSE && _pin[10]._pin == nts::FALSE)
    {
      _pin[13]._pin = nts::FALSE;
      _pin[11]._pin = nts::FALSE;
    }
  else if (_pin[2]._pin == nts::TRUE && _pin[1]._pin == nts::FALSE && _pin[10]._pin == nts::FALSE)
    {
      _pin[13]._pin = nts::FALSE;
      _pin[11]._pin = nts::TRUE;
    }
  else if (_pin[2]._pin == nts::FALSE && _pin[1]._pin == nts::TRUE && _pin[10]._pin == nts::FALSE)
    {
      _pin[13]._pin = nts::FALSE;
      _pin[11]._pin = nts::TRUE;
    }
  else if (_pin[2]._pin == nts::TRUE && _pin[1]._pin == nts::TRUE && _pin[10]._pin == nts::FALSE)
    {
      _pin[13]._pin = nts::TRUE;
      _pin[11]._pin = nts::FALSE;
    }
  else if (_pin[2]._pin == nts::FALSE && _pin[1]._pin == nts::FALSE && _pin[10]._pin == nts::TRUE)
    {
      _pin[13]._pin = nts::FALSE;
      _pin[11]._pin = nts::TRUE;
    }
  else if (_pin[2]._pin == nts::TRUE && _pin[1]._pin == nts::FALSE && _pin[10]._pin == nts::TRUE)
    {
      _pin[13]._pin = nts::TRUE;
      _pin[11]._pin = nts::FALSE;
    }
  else if (_pin[2]._pin == nts::FALSE && _pin[1]._pin == nts::TRUE && _pin[10]._pin == nts::TRUE)
    {
      _pin[13]._pin = nts::TRUE;
      _pin[11]._pin = nts::FALSE;
    }
  else if (_pin[2]._pin == nts::TRUE && _pin[1]._pin == nts::TRUE && _pin[10]._pin == nts::TRUE)
    {
      _pin[13]._pin = nts::TRUE;
      _pin[11]._pin = nts::TRUE;
    }
  else if (_pin[2]._pin == nts::UNDEFINED || _pin[1]._pin == nts::UNDEFINED || _pin[10]._pin == nts::UNDEFINED)
    {
      _pin[13]._pin = nts::UNDEFINED;
      _pin[11]._pin = nts::UNDEFINED;
    }
}

void		Component4008::output_4()
{
  if (_pin[0]._pin == nts::FALSE && _pin[14]._pin == nts::FALSE && _pin[11]._pin == nts::FALSE)
    {
      _pin[13]._pin = nts::FALSE;
      _pin[12]._pin = nts::FALSE;
    }
  else if (_pin[0]._pin == nts::TRUE && _pin[14]._pin == nts::FALSE && _pin[11]._pin == nts::FALSE)
    {
      _pin[13]._pin = nts::FALSE;
      _pin[12]._pin = nts::TRUE;
    }
  else if (_pin[0]._pin == nts::FALSE && _pin[14]._pin == nts::TRUE && _pin[11]._pin == nts::FALSE)
    {
      _pin[13]._pin = nts::FALSE;
      _pin[12]._pin = nts::TRUE;
    }
  else if (_pin[0]._pin == nts::TRUE && _pin[14]._pin == nts::TRUE && _pin[11]._pin == nts::FALSE)
    {
      _pin[13]._pin = nts::TRUE;
      _pin[12]._pin = nts::FALSE;
    }
  else if (_pin[0]._pin == nts::FALSE && _pin[14]._pin == nts::FALSE && _pin[11]._pin == nts::TRUE)
    {
      _pin[13]._pin = nts::FALSE;
      _pin[12]._pin = nts::TRUE;
    }
  else if (_pin[0]._pin == nts::TRUE && _pin[14]._pin == nts::FALSE && _pin[11]._pin == nts::TRUE)
    {
      _pin[13]._pin = nts::TRUE;
      _pin[12]._pin = nts::FALSE;
    }
  else if (_pin[0]._pin == nts::FALSE && _pin[14]._pin == nts::TRUE && _pin[11]._pin == nts::TRUE)
    {
      _pin[13]._pin = nts::TRUE;
      _pin[12]._pin = nts::FALSE;
    }
  else if (_pin[0]._pin == nts::TRUE && _pin[14]._pin == nts::TRUE && _pin[11]._pin == nts::TRUE)
    {
      _pin[13]._pin = nts::TRUE;
      _pin[12]._pin = nts::TRUE;
    }
  else if (_pin[0]._pin == nts::UNDEFINED || _pin[14]._pin == nts::UNDEFINED || _pin[11]._pin == nts::UNDEFINED)
    {
      _pin[13]._pin = nts::UNDEFINED;
      _pin[12]._pin = nts::UNDEFINED;
    }
}

nts::Tristate	Component4008::Compute(size_t pin_num_this)
{
  output_1();
  output_2();
  output_3();
  output_4();
  // output5();
  // output6();
  // output7();
  // output8();
  return (_pin[pin_num_this - 1]._pin);
}
