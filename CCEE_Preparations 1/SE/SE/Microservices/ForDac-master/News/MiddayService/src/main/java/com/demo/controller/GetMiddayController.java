package com.demo.controller;

import org.springframework.beans.factory.annotation.Value;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
public class GetMiddayController {
	@Value("${server.port}")
	private String serverPort;

	@GetMapping("/midday/news")
	public String getToiNews() {
		System.out.println("Port >>>>>>>>>>>> "+serverPort);
		return "News from Midday >> " + serverPort;
	}
}
 