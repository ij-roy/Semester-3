----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    20:50:00 09/22/2024 
-- Design Name: 
-- Module Name:    mux_16_to_1 - Behavioral 
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

entity mux_16_to_1 is
    Port ( A : in  STD_LOGIC_VECTOR (15 downto 0);
	  S : in  STD_LOGIC_VECTOR (3 downto 0);
           Y : out  STD_LOGIC);
end mux_16_to_1;

architecture Behavioral of mux_16_to_1 is
component mux_8_to_1 is
  Port ( 
	A : in  STD_LOGIC_VECTOR (7 downto 0);
	 S1,S2,S3: IN STD_LOGIC;
           Y : out  STD_LOGIC);
	end component;
component mux_2_to_1 is
  Port ( 
  A : in  STD_LOGIC;
           B : in  STD_LOGIC;
           S1 : in  STD_LOGIC;
           Y : out  STD_LOGIC);
			  end component;
signal t1,t2:std_logic;

begin
step1:mux_8_to_1 port map (A=>A(7 DOWNTO 0),S1=>S(0),S2=>S(1),S3=>S(2),Y=>t1);
step2:mux_8_to_1 port map (A=>A(15 DOWNTO 8),S1=>S(0),S2=>S(1),S3=>S(2),Y=>t2);
step3:mux_2_to_1 port map(A=>t1,B=>t2,S1=>S(3),Y=>Y);

end Behavioral;