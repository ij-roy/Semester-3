----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    20:16:54 09/22/2024 
-- Design Name: 
-- Module Name:    octal_to_binary - Behavioral 
-- Project Name: 
-- Target Devices: 
-- Tool versions: 
-- Description: 
--
-- Dependencies: 
--
-- Revision: 
-- Revision 0.01 - File Created
-- Additional Comments: 
--
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity octal_to_binary is
	Port ( A : in  STD_LOGIC;
		B : in  STD_LOGIC;
		C : in  STD_LOGIC;
		D : in  STD_LOGIC;
		E : in  STD_LOGIC;
		F : in  STD_LOGIC;
		G : in  STD_LOGIC;
		H : in  STD_LOGIC;
		EN : in  STD_LOGIC;
		Y0 : out  STD_LOGIC;
		Y1 : out  STD_LOGIC;
		Y2 : out  STD_LOGIC);
end octal_to_binary;

architecture Behavioral of octal_to_binary is

begin
	Y0<=(B OR D OR F OR H )AND EN;
	Y1<= (C OR D OR G OR H) AND EN;
	Y2 <= (E OR F OR G OR H) AND EN;

end Behavioral;