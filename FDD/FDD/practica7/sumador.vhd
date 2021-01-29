library  IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity SUMA is 

	port(x, y, z: in std_logic;
	s: out std_logic;
	a: out std_logic);

end SUMA;

architecture codigo of SUMA is 
begin

	s <= ((x xor y)xor z) ;
	a <= ((x and z) or (x and y) or (y and z));

end codigo;
