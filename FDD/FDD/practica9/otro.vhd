library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity multi is
	 	Port (sel, b: in STD_LOGIC_Vector(1 DOWNTO 0);
		a : in STD_LOGIC_Vector(2 DOWNTO 0);
		salida : out STD_LOGIC_Vector (6 DOWNTO 0)
		);

		end multi;

		ARCHITECTURE arqm of multi IS
		BEGIN

				PROCESS (sel, a, b, salida)
				BEGIN
					IF(sel = "01") THEN
						CASE a IS
						WHEN "000" => salida <= "0110000";
					   	WHEN "001" => salida <= "0100100";
						WHEN "010" => salida <= "0110001";
						WHEN "011" => salida <= "0000001";
						WHEN "100" => salida <= "0000110";
						WHEN OTHERS => salida <= "-------";
					   END CASE;
					ELSIF(sel = "00") THEN
					    CASE b IS
					    WHEN "00" => salida <= "1001111";
						WHEN "01" => salida <= "0011000";
						WHEN "10" => salida <= "0001001";
						WHEN OTHERS => salida <= "-------";
					   END CASE;
					ELSE 
						salida <= "-------";
				   END IF;
				  END PROCESS;
				 END arqm;