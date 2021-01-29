library ieee; 
use ieee.std_logic_1164.all; 
use ieee.std_logic_unsigned.all;

entity sum is port(
	sumP : in std_logic_vector(3 downto 0);
  	sumG : in std_logic_vector(3 downto 0);
  	salida :out std_logic_vector(4 downto 0)
  );
end sum;
 
architecture a_sum of sum is 
begin 
a_sum: process(sumP)
	variable temp: std_logic_vector(4 downto 0);
	begin
	temp := (others => '0');
	temp := temp + sumP;

	salida <= sumG + temp;
	end process;
end  a_sum;
