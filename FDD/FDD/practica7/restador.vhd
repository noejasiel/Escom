library  IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity RESTA is 

	port(x, y, z: in std_logic;
	s: out std_logic;
	a: out std_logic);

end RESTA;

architecture codigo of RESTA is 
begin

	s <= ((x xor y)xor z) ;
	a <= (((not x) and z) or ((not x) and y) or (y and z));

end codigo;
