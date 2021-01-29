library ieee;
use ieee.std_logic_1164.all;

entity MULT is 
	port(a,b: in std_logic_vector (1 downto 0);
	p: out std_logic_vector (3 downto 0));
end MULT;

architecture codigo of mult is 
	signal z: std_logic;
	signal z1: std_logic;
	signal z2: std_logic;
begin
	z <= a(0) and b(1);

	z1 <= a(1) and b(0);
	
	z2 <= a(1) and b(1);

	p(0) <= a(0)  and b(0);
	p(1) <= z xor z1;
	p(2) <= (z and z1) xor z2;
	p(3) <= (z and z1) and z2;
end codigo;


