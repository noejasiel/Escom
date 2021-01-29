library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity multi is
	 	Port (sel, a, b: IN STD_LOGIC_Vector(1 DOWNTO 0);		
		salida :  STD_LOGIC_Vector (6 DOWNTO 0)
		);

		end multi;

		ARCHITECTURE arqm of multi IS
		BEGIN

				PROCESS (sel, a, b, salida)
				BEGIN
					IF(sel = "00") THEN
						IF(a = "00") THEN
							salida <= "0110000"; 
						ELSIF(a = "01") THEN
							salida <= "0100100";
						ELSIF(a = "10") THEN 
							salida <= "0110001";
						ELSIF(a = "11") THEN
							salida <= "0000001";
						ELSE
							salida <= "-------";
					   	END IF;
					ELSIF(sel = "01") THEN
					    IF(b = "00") THEN
					    	salida <= "0000110";
					    ELSIF(b = "01") THEN
							salida <= "1001111";
						ELSIF(b = "10") THEN
							salida <= "0011000";
						ELSIF(b = "11") THEN
							salida <= "0001001";
						ELSE
							salida <= "-------";
					  	END IF;
					ELSE 
						sel <= "--";
				   END IF;
				  END PROCESS;
				 END arqm;
