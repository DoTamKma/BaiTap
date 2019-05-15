-- phpMyAdmin SQL Dump
-- version 4.8.5
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: May 15, 2019 at 06:51 AM
-- Server version: 10.1.39-MariaDB
-- PHP Version: 7.3.5

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `chat`
--

-- --------------------------------------------------------

--
-- Table structure for table `chat_room`
--

CREATE TABLE `chat_room` (
  `room_id` int(10) NOT NULL,
  `name` varchar(225) NOT NULL,
  `create_at` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `chat_room`
--

INSERT INTO `chat_room` (`room_id`, `name`, `create_at`) VALUES
(1, 'BBF', '2019-05-13 09:34:39'),
(2, 'BBF', '2019-05-13 09:34:46'),
(3, 'BBF', '2019-05-13 09:35:43'),
(4, 'BBF', '2019-05-13 09:36:41'),
(5, 'BBF', '2019-05-13 09:36:58');

-- --------------------------------------------------------

--
-- Table structure for table `friend`
--

CREATE TABLE `friend` (
  `friend_id` int(10) NOT NULL,
  `user_id` int(10) NOT NULL,
  `create_at` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  `update_at` timestamp NOT NULL DEFAULT '0000-00-00 00:00:00'
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Table structure for table `messages`
--

CREATE TABLE `messages` (
  `mess_id` int(10) NOT NULL,
  `room_id` int(10) NOT NULL,
  `user_id` int(10) NOT NULL,
  `message` text NOT NULL,
  `create_at` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `messtype_id` int(10) DEFAULT NULL,
  `toID` int(10) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `messages`
--

INSERT INTO `messages` (`mess_id`, `room_id`, `user_id`, `message`, `create_at`, `messtype_id`, `toID`) VALUES
(2, 1, 1, 'Lam viec di', '2019-05-13 09:36:58', NULL, NULL);

-- --------------------------------------------------------

--
-- Table structure for table `messagetype`
--

CREATE TABLE `messagetype` (
  `messtype_id` int(10) NOT NULL,
  `messageType` varchar(255) NOT NULL,
  `create_at` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Table structure for table `users`
--

CREATE TABLE `users` (
  `user_id` int(10) NOT NULL,
  `name` varchar(255) NOT NULL,
  `email` varchar(255) NOT NULL,
  `create_at` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `gender` varchar(6) DEFAULT NULL,
  `sex` varchar(6) DEFAULT NULL,
  `telephone` int(10) DEFAULT NULL,
  `username` varchar(255) DEFAULT NULL,
  `pass` varchar(255) DEFAULT NULL,
  `status_user` varchar(10) DEFAULT NULL,
  `friend_id` int(10) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `users`
--

INSERT INTO `users` (`user_id`, `name`, `email`, `create_at`, `gender`, `sex`, `telephone`, `username`, `pass`, `status_user`, `friend_id`) VALUES
(1, 'HoCa', 'HoCa123@gmail.com', '2019-05-13 09:34:39', NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(2, 'HoCa', 'HoCa123@gmail.com', '2019-05-13 09:34:46', NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(3, 'HoCa', 'HoCa123@gmail.com', '2019-05-13 09:35:43', NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(4, 'HoCa', 'HoCa123@gmail.com', '2019-05-13 09:36:41', NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(5, 'HoCa', 'HoCa123@gmail.com', '2019-05-13 09:36:58', NULL, NULL, NULL, NULL, NULL, NULL, NULL);

--
-- Indexes for dumped tables
--

--
-- Indexes for table `chat_room`
--
ALTER TABLE `chat_room`
  ADD PRIMARY KEY (`room_id`);

--
-- Indexes for table `friend`
--
ALTER TABLE `friend`
  ADD PRIMARY KEY (`friend_id`);

--
-- Indexes for table `messages`
--
ALTER TABLE `messages`
  ADD PRIMARY KEY (`mess_id`),
  ADD KEY `fk_messages_1` (`room_id`),
  ADD KEY `fk_messages_2` (`user_id`),
  ADD KEY `fk_mess` (`messtype_id`);

--
-- Indexes for table `messagetype`
--
ALTER TABLE `messagetype`
  ADD PRIMARY KEY (`messtype_id`);

--
-- Indexes for table `users`
--
ALTER TABLE `users`
  ADD PRIMARY KEY (`user_id`),
  ADD KEY `fk_friend` (`friend_id`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `chat_room`
--
ALTER TABLE `chat_room`
  MODIFY `room_id` int(10) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=6;

--
-- AUTO_INCREMENT for table `friend`
--
ALTER TABLE `friend`
  MODIFY `friend_id` int(10) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT for table `messages`
--
ALTER TABLE `messages`
  MODIFY `mess_id` int(10) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=3;

--
-- AUTO_INCREMENT for table `messagetype`
--
ALTER TABLE `messagetype`
  MODIFY `messtype_id` int(10) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT for table `users`
--
ALTER TABLE `users`
  MODIFY `user_id` int(10) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=6;

--
-- Constraints for dumped tables
--

--
-- Constraints for table `messages`
--
ALTER TABLE `messages`
  ADD CONSTRAINT `fk_3` FOREIGN KEY (`messtype_id`) REFERENCES `messagetype` (`messtype_id`),
  ADD CONSTRAINT `fk_mess` FOREIGN KEY (`messtype_id`) REFERENCES `messagetype` (`messtype_id`),
  ADD CONSTRAINT `fk_messages_1` FOREIGN KEY (`room_id`) REFERENCES `chat_room` (`room_id`),
  ADD CONSTRAINT `fk_messages_2` FOREIGN KEY (`user_id`) REFERENCES `users` (`user_id`);

--
-- Constraints for table `users`
--
ALTER TABLE `users`
  ADD CONSTRAINT `fk_friend` FOREIGN KEY (`friend_id`) REFERENCES `friend` (`friend_id`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
