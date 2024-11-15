----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    18:41:12 10/15/2024 
-- Design Name: 
-- Module Name:    ripple_counter - Behavioral 
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

entity ripple_counter is
	port(
	clk : in STD_LOGIC;      
	enable : in STD_LOGIC;  
	reset : in STD_LOGIC;             
	count : out STD_LOGIC_VECTOR(3 downto 0) 
	);
end ripple_counter;

architecture Behavioral of ripple_counter is
component d_ff is
port ( d      : in std_logic;
        clk    : in std_logic;
        enable : in std_logic;
        reset  : in std_logic;
        q      : out std_logic);
end component;
signal t:std_logic_vector (3 downto 0); signal d_input : std_logic_vector(3 downto 0);
begin
	d_input(0) <= not t(0);
	d_input(1) <= not t(1);
	d_input(2) <= not t(2);
	d_input(3) <= not t(3);
	step1:d_ff port map(d=>d_input(0),clk=>clk,enable=>enable,reset=>reset,q=>t(0));
	step2:d_ff port map(d=>d_input(1),clk=>t(0),enable=>enable,reset=>reset,q=>t(1));
	step3:d_ff port map(d=>d_input(2),clk=>t(1),enable=>enable,reset=>reset,q=>t(2));
	step4:d_ff port map(d=>d_input(3),clk=>t(2),enable=>enable,reset=>reset,q=>t(3));
process(clk, reset)  
	begin
	if reset = '1' then
		count <= "0000";  
	elsif rising_edge(clk) then
		if enable = '1' then
			count <= t;  
		end if;
	end if;
 end process;
end Behavioral;