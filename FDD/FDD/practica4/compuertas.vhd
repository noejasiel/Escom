library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity COMPUERTAS is
	 	Port (sel : in STD_LOGIC_Vector (2 downto 0);		
		a, b, c : in STD_LOGIC;
		salida : out STD_LOGIC 
		);

		end COMPUERTAS;

		ARCHITECTURE funciones of COMPUERTAS IS
		BEGIN

				PROCESS (sel, a, b, c)
				BEGIN
					CASE sel IS
					WHEN "001" => salida <= a and b and c;
				   	WHEN "010" => salida <= a or b or c;
					WHEN "011" => salida <= not(a and b and c);
					WHEN "100" => salida <= not(a or b or c);
					WHEN "101" => salida <= a xor b xor c;
					WHEN "110" => salida <= not(a xor b xor c);
					WHEN OTHERS => salida <='0';
				   END CASE;
				  END PROCESS;
				 END funciones;





