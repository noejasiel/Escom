library ieee;
use ieee.std_logic_1164.all;

entity and2 is
	port( y0 :out std_logic;
		a, b, c, d :in std_logic );
end entity and2;

architecture and2 of and2 is
begin
	y0 <= a and b and c and d;
end architecture and2;
