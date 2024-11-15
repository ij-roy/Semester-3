--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   17:40:34 10/15/2024
-- Design Name:   
-- Module Name:   /home/ise/Assignment3/d_ff_tb.vhd
-- Project Name:  Assignment3
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: d_ff
-- 
-- Dependencies:
-- 
-- Revision:
-- Revision 0.01 - File Created
-- Additional Comments:
--
-- Notes: 
-- This testbench has been automatically generated using types std_logic and
-- std_logic_vector for the ports of the unit under test.  Xilinx recommends
-- that these types always be used for the top-level I/O of a design in order
-- to guarantee that the testbench will bind correctly to the post-implementation 
-- simulation model.
--------------------------------------------------------------------------------
LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
 
-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--USE ieee.numeric_std.ALL;
 
ENTITY d_ff_tb IS
END d_ff_tb;
 
ARCHITECTURE behavior OF d_ff_tb IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT d_ff
    PORT(
         d : IN  std_logic;
         clk : IN  std_logic;
         enable : IN  std_logic;
         reset : IN  std_logic;
         q : OUT  std_logic
        );
    END COMPONENT;
    

   --Inputs
   signal d : std_logic := '0';
   signal clk : std_logic := '0';
   signal enable : std_logic := '0';
   signal reset : std_logic := '0';

 	--Outputs
   signal q : std_logic;

 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: d_ff PORT MAP (
          d => d,
          clk => clk,
          enable => enable,
          reset => reset,
          q => q
        );

   -- Clock process definitions
   clk_process :process
   begin
		clk <= '0';
		wait for 5 ns;
		clk <= '1';
		wait for 5 ns;
   end process;
 

   -- Stimulus process
   stim_proc: process
   begin	
		d <= '0';
		enable <= '0';
		reset <= '0';
		wait for 20 ns;
		reset <= '1';
		wait for 10 ns;
		reset <= '0';
		wait for 10 ns;
	  
		d <= '1';
		enable <= '1';
		wait for 20 ns;
		d <= '0';
		enable <= '0';
		wait for 20 ns;
		reset <= '1';
		wait for 10 ns;
		reset <= '0';
		wait for 10 ns;
		enable <= '1';
		
		d <= '1';
		wait for 20 ns;
		enable <= '0';
		d <= '0';
		wait for 20 ns;


      wait;
   end process;

END;