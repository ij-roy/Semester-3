----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    18:07:21 10/15/2024 
-- Design Name: 
-- Module Name:    siso - Behavioral 
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

entity siso is
	port(
	clk:in std_logic;
	enable:in std_logic;
	reset:in std_logic;
	serial_in:in std_logic;
	serial_out:out std_logic
	);
end siso;

architecture Behavioral of siso is
	component d_ff is
	port ( d      : in std_logic;
			  clk    : in std_logic;
			  enable : in std_logic;
			  reset  : in std_logic;
			  q      : out std_logic);
			  end component;
			  signal q0,q1,q2,q3:std_logic;
	begin
		step1:d_ff port map(d=>serial_in,clk=>clk,enable=>enable,reset=>reset,q=>q3);
		step2:d_ff port map(d=>q3,clk=>clk,enable=>enable,reset=>reset,q=>q2);
		step3:d_ff port map(d=>q2,clk=>clk,enable=>enable,reset=>reset,q=>q1);
		step4:d_ff port map(d=>q1,clk=>clk,enable=>enable,reset=>reset,q=>q0);
		serial_out<=q0;
end Behavioral;