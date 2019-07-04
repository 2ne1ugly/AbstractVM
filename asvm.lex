%{
  #include <iostream>
  #include "abstractVM.h"
%}
%option noyywrap
%option c++


string  \"[^\n"]+\"

alpha   [A-Za-z]
dig     [0-9]
name    ({alpha}|{dig}|\$)({alpha}|{dig}|[_.\-/$])*
num     [-+]?{dig}+
num1    [-+]?{dig}+\.?([eE][-+]?{dig}+)?
num2    [-+]?{dig}*\.{dig}+([eE][-+]?{dig}+)?
number  {num1}|{num2}
comment ;.+
int8    int8\({num}\)
int16   int16\({num}\)
int32   int32\({num}\)
float   float\({number}\)
double  double\({number}\)

%%
;;				{return (int)eCommandType::EndStream;}
{comment}       {return (int)eSeperatorType::Comment;}
exit			{return (int)eCommandType::Exit;}
push			{return (int)eCommandType::Push;}
pop				{return (int)eCommandType::Pop;}
dump			{return (int)eCommandType::Dump;}
assert			{return (int)eCommandType::Assert;}
add				{return (int)eCommandType::Add;}
sub				{return (int)eCommandType::Sub;}
mul				{return (int)eCommandType::Mul;}
div				{return (int)eCommandType::Div;}
mod				{return (int)eCommandType::Mod;}
print			{return (int)eCommandType::Print;}
{int8}			{return (int)eOperandType::Int8;}
{int16}         {return (int)eOperandType::Int16;}
{int32}         {return (int)eOperandType::Int32;}
{float}         {return (int)eOperandType::Float;}
{double}        {return (int)eOperandType::Double;}
[ \t]			{return (int)eSeperatorType::Ws;}
[\n]			{return (int)eSeperatorType::Nl;}
.               {return -1;}
%%
