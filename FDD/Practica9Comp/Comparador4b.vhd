library ieee;
use ieee.std_logic_1164.all;

entity comparadoor is
	port( a,b : in std_logic_vector(3 downto 0);
	display : out std_logic_vector (6 downto 0)
	);
end comparadoor;

architecture comparador of comparadoor is
begin
process(a, b)
	begin
	if(a > b)then
		display <= "0000111";
	elsif(a < b)then
		display <= "0110001";
	else 
		display <= "0110111";
	end if;
 end process;
 end comparador;